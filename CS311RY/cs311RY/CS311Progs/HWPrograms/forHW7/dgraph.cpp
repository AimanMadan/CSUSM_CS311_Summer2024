//CS311 Yoshii SUM24 dgraph.cpp 
// INSTRUCTION:
//   Complete all the functions you listed in dgraph.h
//   Comment the file completely using How to Comment file.
//   Use HW6-help.docx to finish the functions.
//  NEVER delete my comments!!!
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Aiman Madan
// File Type: Aiman Madan
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph()
 // initialize vertexName (blank) and visit numbers (0) for all slots of the table
 // - need a loop
 // initialize countUsed to be 0
{
  for(int i = 0; i < SIZE; i++)
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].visit = 0;
    }
   countUsed = 0; 
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// If we do not do this, will the llist destructor be called automatically? Try it.
{
}

void dgraph::fillTable()  // be sure to read from a specified file
// you will have to use a linked list function addRear. 
{
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help
  while(fin >> Gtable[countUsed].vertexName)  // IF I CAN READ THE NAME
    { 
      fin >> Gtable[countUsed].outDegree;

      //Then for the OutDegree times (for-loop):
      for(int i = 0; i < Gtable[countUsed].outDegree; i++)
	      {
          char x;
	        fin >> x;
	        (Gtable[countUsed].adjacentOnes).addRear(x);   // this is a slist function from HW3
        }
  
      countUsed++;
    }

  fin.close();
}


void dgraph::displayGraph() // be sure to display
// in a really nice table format -- all columns but no unused rows and include the total number of edges at the very top (you have to sum it up)
// you will have to use a linked list function displayAll. 
{
    int totalEdges = 0;

    // Calculate the total number of edges
    for (int i = 0; i < countUsed; ++i) {
        totalEdges += Gtable[i].outDegree;
    }

    cout << "Total edges: " << totalEdges << endl;
    cout << "Vertex\tOutDegree\tVisit\tAdjacency List" << endl;

    for (int i = 0; i < countUsed; ++i) {
        cout << Gtable[i].vertexName << "\t" << Gtable[i].outDegree << "\t\t" << Gtable[i].visit << "\t\t";
        Gtable[i].adjacentOnes.displayAll();
        cout << endl;
    }
}

int dgraph::findOutDegree(char V)// throws exception BadVertex if not found
{// do not use a loop - go directly to a slot using V!!
  int temp = int(V) -65; // converts the char to an int
  if(temp >=0 && temp < countUsed)
    {
      return Gtable[temp].outDegree;
    }
  else
    {
      throw BadVertex();
    }
}

slist dgraph::findAdjacency(char V)// throws exception BadVertex if not found
{// do not use a loop - go directly to a slot using V!!
  int temp = int(V) -65; 
  if(temp >=0 && temp < countUsed)
    {
      return Gtable[temp].adjacentOnes;
    }
  else
    {
      throw BadVertex();
    }
}

//3) Must add two functions to dgraph.h and dgraph.cpp


void dgraph::visit(int visitNum, char vertex) {

  /*- void visit(int, char) 
   which will enter the given visit number
   for a given vertex.
   This is to indicate the order in which
   vertices were visited.

 Do not use a loop to look for the vertex.
 Convert A to slot 0, B to slot 1 etc.*/

    int index = vertex - 'A'; // Convert character to array index
    Gtable[index].visit = visitNum;
 }

bool dgraph::isMarked(char V)
{
  /*- bool isMarked(char) 
  which returns true if a given vertex was
  already visited
  (0 means not visited so return false)
 Do not use a loop to look for a vertex
*/
  int index = V - 'A'; // Convert character to array index
  return Gtable[index].visit != 0;

}