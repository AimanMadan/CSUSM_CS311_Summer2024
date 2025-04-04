// CS311 Demo : Try this
// Pass by Value is supposed to make a copy.  Does it?

using namespace std;
#include <iostream>
#include "rlist.h"

void copyTest(llist X)
{
  cout << "X in copy test" << endl;
  X.displayAll();
  X.addRear(1);
  X.displayAll();
}

int main()
{
  llist B;

  B.addRear(2);

  cout << "B before" << endl;
  B.displayAll();

  copyTest(B);

  cout << "B after" << endl;
  B.displayAll();
  
}


