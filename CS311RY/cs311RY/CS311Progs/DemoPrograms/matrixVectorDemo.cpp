// CS311 Yoshii - matrix-vector demo
// Demonstrates a matrix containing a vector of chars
// in each slot.
// --------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

void displayAll(vector<char> V)
{ cout << "[";
 for (int i = 0; i < V.size(); i++)
    cout << V[i];
 cout << "]";
}

int main()
{
  vector<char> M[3][3];  // every slot is a vector

  char x; // user input

  for (int row = 0; row <= 2; row++)
    for (int col = 0; col <= 2; col++)
      { cout << "For row " << row << " column " << col << endl;
        cout << "    Enter a character:";
        cin >> x; 
        M[row][col].push_back(x);
        cout << "    Enter a character:";
        cin >> x; 
        M[row][col].push_back(x);
      }// to next slot

  for (int row = 0; row <=2; row++)
    {
    for (int col = 0; col <=2; col++)
      { displayAll(M[row][col]); cout << " | ";}
    cout << endl; // end of row
    }

}
