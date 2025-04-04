// CS311 Yoshii - Polymorphism = object type for which function
// This demo program shows how inheritance and virtual functions work
// with an array of pointers to run time stack objects
//  Virtual functions are useful when you have an array of pointers
//  to different types of objects; which function to call is based on
//  the object type, not the pointer type.
// --------------------------------------------------------
#include "girl.h"
#include "boy.h"
#include <iostream>

// girl and boy inherit from person a virtual function doit
int main()
{

  person *students[2];  // an array of pointers to person objects  
  girl G;
  boy B;

  students[0] = &G;  // to a girl object on the run time stack
  students[1] = &B;  // to a boy object on the run time stack 

  // alternative ways of calling the function
  students[0]->doit();  // ** boy's doit
  (*students[1]).doit();  // ** girl's doit

  // ** destructors are called 
}
