// CS311 Yoshii SUM24 - Shortest Path EC2 - Use as is - DO NOT CHANGE
//---------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "dgraph2.h"

int main()
{
  dgraph T;
  
  T.filltable();

  T.makeTree(0);  // 0th entry is now in Tree
  T.displayTable();
  char a;  // user input for stopping the loop
  while (!T.allTree())   // Until all are in Tree
    { 
      T.makeTree(T.findSmallest());
      T.displayTable();
      cout << "cont?"; cin >> a;
    }

  // the shortest path from the 0's vertex to all others
  // have been determined.
  
  cout << "Enter a goal vertex or Q: ";
  cin >> a;
  while (a != 'Q')
    { T.displayPath(a);  // display the shortest path 
      cout << "Enter a goal vertex or Q: ";
      cin >> a;
    }

}// end of main
