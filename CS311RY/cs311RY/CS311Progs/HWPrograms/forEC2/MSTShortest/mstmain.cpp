// CS311 Yoshii SUM24 - MST EC2  - Use as is - DO NOT CHANGE!!!
// ----------------------------------------------------------------
#include <iostream>
using namespace std;

#include "dgraph2.h"

int main()
{
  dgraph T;
  
  T.filltable();

  T.makeTree(0);    // 0th entry is marked as Tree
  T.displayTable();
  char a;  // user input for stopping the loop
  while (!T.allTree())   // until all are in Tree
    { 
      T.makeTree(T.findSmallest());
      T.displayTable();
      cout << "cont?"; cin >> a;
    }
  T.displayMST();  // display the edges of the MST
}//end of main
