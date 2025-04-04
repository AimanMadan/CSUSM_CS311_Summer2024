// CS311 Yoshii - Polymorphism = object type determines the function
// This demo program shows how inheritance and virtual functions work
// with an array of pointers to heap objects.
//  Virtual functions are useful when you have an array of pointers
//  to different types of objects; which function to call is based on
//  the object type, not the pointer type.
// ---------------------------------------------------------
#include "girl.h"
#include "boy.h"
#include <iostream>

// girl and boy inherit from person a virtual function doit
int main()
{

  person *students[2];  // an array of pointers to person objects  

  students[0] = new boy;     // constructors are called
  students[1] = new girl;    // constructors are called

  // alternative ways of calling the function
  (*students[0]).doit();  // ** boy's doit
  students[1]->doit();    // ** girl's doit

  // ** destructors are not called
}
