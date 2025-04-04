// CS311 Yoshii - Demo on file IO with a user input file name
// This makes sure it stops at the end of file no matter what
// --------------------------------------------------------
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{ string name[10];
  int age[10];

  string fname;  // file name

  cout << "Enter a file name: ";
  cin >> fname;

  ifstream fin (fname.c_str(), ios::in); // declare and open 

  int i = 0;
  while (fin >> name[i]) // eof does not work well with emacs
    {
      fin >> age[i];
      i++;
    }
  fin.close();
 
  ofstream fout (fname.c_str(), ios::out); // declare and open the output stream to the same file

  cout << "outputting... " << endl;
  for (int j = 0; j < i; j++)
    {
      fout << name[j] << endl; 
      fout << age[j] << endl; 
    }
}
