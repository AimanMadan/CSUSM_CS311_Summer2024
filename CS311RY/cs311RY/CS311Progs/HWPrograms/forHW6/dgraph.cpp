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
// File Type: dgraph implementation file
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph()
{
  // initialize vertexName (blank) and visit numbers (0) for all slots of the table
 // - need a loop
  for (int i = 0; i < SIZE; i++)
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].visit = 0;
    }

    // initialize countUsed to be 0
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
  char x;
   while(fin >> Gtable[countUsed].vertexName)  // IF I CAN READ THE NAME
    { 
      fin >> Gtable[countUsed].outDegree;

      //Then for the OutDegree times (for-loop):
      for(int i = 0; i < Gtable[countUsed].outDegree; i++)
	{
	  fin >> x;
	  (Gtable[countUsed].adjacentOnes).addRear(x);   // this is a slist function from HW3
        }
  
      // update
      countUsed++;
    }

  fin.close();
}


void dgraph::displayGraph() // be sure to display
// in a really nice table format -- all columns but no unused rows and include the total number of edges at the very top (you have to sum it up)
// you will have to use a linked list function displayAll. 
{
  
} 

int dgraph::findOutDegree(char V)// throws exception BadVertex if not found
{// do not use a loop - go directly to a slot using V!!
}

slist dgraph::findAdjacency(char V)// throws exception BadVertex if not found
{// do not use a loop - go directly to a slot using V!!
  
}
