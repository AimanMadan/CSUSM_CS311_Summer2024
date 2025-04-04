// CS311 Yoshii - matrix demo
// --------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  char M[3][3];

  for (int row = 0; row <= 2; row++)
    for (int col = 0; col <= 2; col++)
      { cout << "For row " << row << " column " << col << endl;
        cout << "    Enter a character:";
        cin >> M[row][col];
      }

  for (int row = 0; row <=2; row++)
    {
    for (int col = 0; col <=2; col++)
      cout << M[row][col] << " | ";
    cout << endl;
    }

}
