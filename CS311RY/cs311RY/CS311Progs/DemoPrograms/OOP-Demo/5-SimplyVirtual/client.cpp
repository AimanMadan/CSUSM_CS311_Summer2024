// CS311 Yoshii - 
// this demo program shows how inheritance and virtual functions work
// without pointers to objects
// --------------------------------------------------
#include "girl.h"
#include <iostream>
#include <vector>

// girl inherits from person
int main()
{
  cout << "-- First with girl A and person B " << endl;

  girl A;    // calls person const first even when girl const was there
  A.doit();  // girls doit is called 

  person B;
  B.doit();  // persons doit is called

  cout << "-- Person gets a girl " << endl;

  B = A;  // person gets girl does work
  //  A = B;   but girl gets person does NOT work  
  B.doit();   // persons doit is called whether virtual or not 

  char x;
  cout << "Now with a person array with a Girl and a Person?";
  cin >> x;
  person L[2];  
  L[0] = A;     // yes I can assign a girl to the person array
  L[1] = B;     // person is assigned
  L[0].doit();  // persons doit for the girl - virtual or not
  L[1].doit();  

}
