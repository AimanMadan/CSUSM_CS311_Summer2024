// CS311 Yoshii - MST and Shortest Path Extra Credit dgraph2.h
// linked list classes should have been updated to use elem.h
// DO NOT CHANGE!!!
//----------------------------------------------------------

#include <iostream>
using namespace std;
#include "slist.h"

const int MAX = 20;  // 20 rows for the graph table

// for each graph table entry
struct vertex
{
  char Name; 
  int Out;
  int Visit;    // not used for EC but OK to keep it
  slist Adj;

  int  DistTo; // new - edge or path cost
  char From;   // new - last edge is from?
  char Kind;   // new - tree (T) or fringe (F)?
};


class dgraph
{
 private:
  vertex G[MAX];  // G is the table
  int count;      // how many slots of G are used
  
 public:
  dgraph();
  ~dgraph();

  void filltable();     // fill reading from the input file
  void displayTable();  // display the table in a nice format

  // new functions follow -----------------------

  void makeTree(int);    // mark as T (Tree) the given entry of table
  int  findSmallest();   // find the smallest distTo F (Fringe) entry
  bool allTree();        // every thing is T (tree)? 

  // this is for MST only
  void displayMST();     // display the edges of MST at the end

  // this is for Shortest Path only
  void displayPath();   // display the shortest path to whatever the
                        // user specifies

 protected:  // Utility function
  void  makeFringe(el_t, char, int); //update a fringe vertex entry 

}; 
