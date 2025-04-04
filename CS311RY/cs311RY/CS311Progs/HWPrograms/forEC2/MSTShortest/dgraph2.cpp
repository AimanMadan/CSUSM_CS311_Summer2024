// CS311 Yoshii SUM24 - MST and Shortest Path Extra Credit dgraph2.cpp
// linked list classes should have been updated to use elem.h
//----------------------------------------------------------

// ========================================
// EC on **
// Name: **
// File: dgraph2.h implementation
// =========================================

using namespace std;
#include "dgraph2.h"
#include <fstream>
#include <string>

dgraph::dgraph()
{ count = 0; }

dgraph::~dgraph() 
{ count = 0;}

// fill the table with a file content
void dgraph::filltable()
{
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;
  ifstream fin (filename.c_str(), ios::in);
  **  // note that you need to create el_t object before adding to list
  fin.close();
}

// display the table in a very readable format
void dgraph::displayTable()
{
  **
}


// is everyone in the Tree?
bool dgraph::allTree()
{
 **
}

// find the edges in the MST (at the end)
void dgraph::displayMST()
{ cout << "Edges in the MST are:" << endl;
  **
}

// retrieve and display the shortest path to V 	(at the end)
void dgraph::displayPath(char V)
{ cout << "Edges in the shortest path are:" << endl;
  **
}


// find the fringe vertex with the smallest DISTO. 
// return the location in the table.
int dgraph::findSmallest()
{ **
}
   
// Adding i's vertex to tree (T)
// causing more Fringe vertices to be added
void dgraph::makeTree(int i)
{ 
  cout << "Adding " << G[i].Name << " to tree" << endl; 
  ** // Make it T
    ** // get all adjacent vertices 
    ** // calls makeFringe on each adjacent vertex 
}

// Utility: Enter or update the DISTO of a fringe vertex
void dgraph::makeFringe(el_t X, char V, int soFar)
{ 
  // X is the fringe vertex (a node's Elem from slist)
  // V is which tree vertex the edge came from
  // soFar is the distance to V so far (used for shortest path only)

  **
}


