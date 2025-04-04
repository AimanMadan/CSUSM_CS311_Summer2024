// CS311 Demo: Try this
// = is supposed to make a copy.  Does it???

using namespace std;
#include <iostream>
#include "rlist.h"


int main()
{
  llist A;
  llist B;

  cout << "A" << endl;
  A.displayAll();

  B.addRear(1);
  cout << "B" << endl;
  B.displayAll();

  A = B ;  // I want to make A look the same as B

  B.addRear(2);  // this should not have any effect on A
  cout << "B after" << endl;
  B.displayAll();

  cout << "A after" << endl;
  A.displayAll();
  
}


