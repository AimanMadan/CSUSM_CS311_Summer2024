// CS311 Yoshii dgraph.h that uses slist.h
//   DO NOT CHANGE but read carefully!!!
//   slist functions will be called from dgraph
//-----------------------------------------------------

// =======================================================
// HW#: HW6 dgraph
// Name: Aiman Madan
// File Type: dgraph header file
// ==================================================

#include <iostream>
#include "slist.h"
using namespace std;

//-----  globally setting up an alias ---------------------
const int SIZE = 26;   // for the size of the graph table for A-Z

// this will be in each GTable slot
struct Gvertex
{
  char vertexName;      //the vertex Name
  int outDegree;	//the Out degree
  slist adjacentOnes;   //the adjecent vertices in an slist
  int visit;            // This will hold the visit number in HW7 
};

class dgraph
{

private:
  Gvertex Gtable[SIZE];  // a table representing a dgraph
  int  countUsed; // how many slots of the Gtable are actually used

public:

  class BadVertex {};  // thrown when the vertex is not in the graph
 
  dgraph();    // initialize vertexName (blank) and visit numbers (0)
               // initialize countUsed to be 0
  ~dgraph();   // do we have to delete all nodes of slists in table??
	       // Question: If we do not do this, will the llist destructor
               // be called automatically??? Try it.

 // read from the input file and fill GTable
  void fillTable();  

 // displays in an easy to read table format 
  void displayGraph(); 

// returns the out degree of a given vertex - may throw BadVertex
  int findOutDegree(char);  
	
// returns the adjacency list of a given vertex - may throw BadVertexx
  slist findAdjacency(char);  

};


