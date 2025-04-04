//CS311 Yoshii SUM24 client2.cpp
//INSTRUCTION:
//Look for ** to complete this program and comments.
//The string output should match my hw1queueDemo.out 
// NEVER delete my comments!!!!
//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Aiman Madan
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: Given a set of characters, we would like to generate (display) all possible strings consisting of these characters.
//Algorithm: FIFO

int main()
{ 
  
  queue Q; //create a queue


//  place "A", "B", "C" in the queue

      Q.add("A");
      Q.add("B");
      Q.add("C");

   //  while loop -- indefinitely while(true)
   while(true)
    {
      try

      // do the steps noted in the notes 
      {
        std::string frontElem;
      Q.frontElem(frontElem); // Get the front element
      std::cout << frontElem << std::endl;

      // Add the string + "A", "B", "C"
      Q.add(frontElem + "A");
      Q.add(frontElem + "B");
      Q.add(frontElem + "C");

      // Remove the front element
      Q.remove(frontElem);
    }
    catch(queue::Overflow) // Catch overflow exception
      {
        std::cerr << "Queue Overflow. Exiting." << std::endl;
        break;
    
      }// end of loop
    } 
    return 0; 
}
