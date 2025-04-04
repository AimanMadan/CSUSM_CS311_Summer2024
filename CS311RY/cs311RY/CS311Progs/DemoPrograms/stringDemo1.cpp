// cs311 Yoshii - Demostrates conversion from char to int
// where chars are obtained from a string
// --------------------------------------------------------
#include <iostream>
using namespace std;
#include <string>

int main()
{
  string mystring;
  cout << "Give me a string of integers and * and +:";
  cin  >> mystring;
  
  int i = 0;
  while (mystring[i] != '\0')  // until the end of the string
    { 
      char let;
      let = mystring[i];
      cout << i <<  "th == ";
      cout << let << endl;

      // conversion of let to int
      if ((let != '*') && (let != '+'))
	{ int x = int(let)-48;
          cout << "integer value is: " << x << endl;
      }

      i++;  // next char
    }//end of while

}// end of main
