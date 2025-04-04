// CS311 YOSHII SUM24 hw7client.cpp

//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Aiman Madan
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include both dgraph and stack
#include "stack.h"
#include "dgraph.h"
using namespace std;

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  dgraph table; 
  slist tempList;            
  stack tableStack;          
  int visitNum = 0;
  el_t vertex; 

  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that for the comments. 
  // Make sure all couts are included and that they look nice.
  //Display the graph before DFS begins.
  table.fillTable();         // fill the graph
  table.displayGraph();      // display without assigned visit numbers 
  tableStack.push('A');      // start with A

  // While the stack is not empty
  while(!tableStack.isEmpty())
  {
    // Remove a vertex v from the stack.
    tableStack.pop(vertex);
    cout << "Removed " << vertex << " from stack" << endl;

    // If v is not marked yet (visit number is 0)
    if(!table.isMarked(vertex))
    {
      visitNum++;
      // Mark it (visit it **) and inform the user
      cout << "Visit " << vertex << " as " << visitNum << endl;

      table.visit(visitNum, vertex);
      tempList = table.findAdjacency(vertex);

      // Get its adjacency list
      if(tempList.isEmpty())
      {
        // If no adjacent ones inform the user
        cout << "Deadend reached – backup" << endl;
      }
      else
      {
        // Else put adjacent ones on the stack (delete from the rear and push) informing the user
        el_t adjVertex;
        while(!tempList.isEmpty())
        {
          tempList.deleteRear(adjVertex);
          tableStack.push(adjVertex);
          cout << "Pushed " << adjVertex << " onto stack" << endl;
        }
      }
    }
    else
    {
      // Else inform the user
      cout << vertex << " had been visited already - backup." << endl;
    }

    // Display the stack clearly labeling it as the current stack
    cout << "Stack: ";
    tableStack.displayAll();
    cout << endl;
  }

  // Display the Graph nicely with visit numbers for all vertices
  table.displayGraph();
}