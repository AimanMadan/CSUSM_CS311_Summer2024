// CS311 Yoshii - string use demo. 
// Note that = and == have been overloaded in the string class.
// Also note that the null char '\0' is found at the end of the string.
// This program asks the user to enter two words.  It will check to see
// if they are the same.  Otherwise, the two words will be concatenated.
// ----------------------------------------------------
#include<string>
#include <iostream>
using namespace std;

int main()
{
  string word1, word2;
  string phrase;

  cout << "Enter a word: ";
  cin >> word1;
  cout << "Enter another word: ";
  cin >> word2;

  if (word1 == word2)  cout << "Oops they are the same" << endl;
  else {    phrase =  word1 + " " + word2 + "." ;
	    cout << phrase << endl; }
  // concatenation of two words using +

  string S;
  cout << "Give me a 4 letter word: ";
  cin >> S; 
  // is it a 4 letter word?
  if (S[4] == '\0') cout << "Hey!!!" << endl;
}
