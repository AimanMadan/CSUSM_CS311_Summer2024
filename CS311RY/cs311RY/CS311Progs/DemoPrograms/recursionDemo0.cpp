// CS311 Yoshii - Recursive Function demonstration
// ------------------------------------------------------
#include<iostream>
using namespace std;

// this recursive function calls itself with end reduced by red each time
// Infinite Recursion
void divide(int L[], int count, int end)
{ count++;
  cout << count << " Divide was called and its AR was pushed" << endl;
  end = end - 1; // end of the array goes down by 1
  if (end != 0)
    divide(L, count, end);  // recursive call reducing end by red
}

int main()
{
  int MyArray[10];

  cout << "I will need 3 integers from you." << endl;
  for (int i = 0; i< 3; i++)
    {
    cout << "Enter::";
    cin >> MyArray[i];
    }
  divide(MyArray, 0, 2);
}
