// CS311 Yoshii - Pointer Demo
// Note: Any attempt to follow a dangling pointer will cause a 
// segmentation fault.
// But in some cases, it takes a while before the system realizes that
// the pointer is dangling.  
// Any acess to a non-existing cell will eventually cause
// a segmentation fault.
// What will the following do?  Try on empress and then on your PC
// --------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int* P;

  P = new int;

  cout << "Address of an existing pointer: " << P << endl;

  delete P;
  cout << "Address of the deleted pointer: " << P << endl;

       P = NULL;
     cout << "Address of a NULL pointer: " << P << endl;

  cout << "Going to a non-exisiting cell.. " << endl;  
  *P = 3;  // going to a non-existing cell 

}
