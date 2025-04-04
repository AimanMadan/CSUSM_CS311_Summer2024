// CS311 Yoshii - Recursive Function demonstration
// Reduces the list size each time
// ------------------------------------------------------
#include<iostream>
using namespace std;

// display the array L from beg to end
void display(int L[], int beg, int end)
{
  for (int i = beg; i <= end; i++)
    cout << L[i] << " " ;
  cout << endl;
}


// this recursive function calls itself with end reduced by red each time
void divide(int L[], int beg, int end, int red)
{
  cout << "Divide was called: ";
  display(L, beg, end); // display L from beg to end

  if ((end - beg) < 1)  // the base case to stop the recursion
      cout << "Ending recursion." << endl; 
  else
    divide(L, beg, end-red, red);  // recursive call reducing end by red
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

  cout << "Reduce the list by how much each time??";
  cin >> red;

  divide(MyArray, 0, 9, red);
}
