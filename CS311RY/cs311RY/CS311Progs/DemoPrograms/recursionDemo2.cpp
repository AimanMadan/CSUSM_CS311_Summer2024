// CS311 Yoshii - recursion demonstration
// of cutting a list in 1/2 each time
// ----------------------------------------------
#include<iostream>
#include<cmath>
using namespace std;

// displays L from beg to end
void display(int L[], int beg, int end)
{
  for (int i = beg; i <= end; i++)
    cout << L[i] << " " ;
  cout << endl;
}


// this recursive function is called with L being cut in 1/2 each time
void divide(int L[], int beg, int end, string j)
{ int mid;

  j = j + "  ";  // j is used for indentation of couts
  cout << j+"Divide was called with: ";
  display(L, beg, end);

  if (beg >= end) // the base case
    { cout << j+"Recursion is ending" << endl; return; }

  mid = floor((beg+end)/2);  // mid point 
  cout << j+"Mid point has " << L[mid] << endl;

  cout << j+"For the first half " << endl;
    divide(L, beg, mid-1, j);  // recursive call for the first half

  cout << j+"For the second half " << endl;
    divide(L, mid+1, end, j); // recursive call for the second half

}

int main()
{
  int MyArray[10];
  int red;

  cout << "I will need 10 integers from you." << endl;
  for (int i = 0; i< 10; i++)
    {
    cout << "Enter::";
    cin >> MyArray[i];
    }
 
  string j = "";

  divide(MyArray, 0, 9, j);
}
