// CS311 Yoshii - Pointer to Arrays Demo
// A pointer to an array goes to the first slot of the array
// You can offset from it to access any slot
//---------------------------------------------------
#include<iostream>
using namespace std;

// x and y are pointers to characters
  void swap(char *x, char *y)
  {
    char temp;
    temp = *x;   // temp gets the value of x cell
    *x = *y;     // x cell gets the value of y cell
    *y = temp;   // y cell gets the value of temp
  }
 

int main()
  {
    char str[] = "ABC";  // char array  (this cannot be string str)
    char* s;
    s = str;   // pointer s points to the first char of str
    cout << *s << endl;  // the first char is displayed
    swap(s+1, s+2);
    cout << str << endl;  // cout char string 

    // with an integer array
    int a[3] = {1,2,3};
    int* x;
    x = a;  
    cout << *x << endl;
    cout << *x+1 << endl;
    cout << *x+2 << endl;
  }
