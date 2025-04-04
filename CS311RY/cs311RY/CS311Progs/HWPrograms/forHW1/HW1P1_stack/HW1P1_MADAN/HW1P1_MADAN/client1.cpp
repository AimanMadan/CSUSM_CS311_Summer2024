//CS311 Yoshii SUM24 client1.cpp
//INSTRUCTION:
//Look for ** to complete this program and comments (Use control-S)
//The output should match my hw1stackDemo.out 
// NEVER delete my comments !!!
//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Aiman Madan
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: Convert Postfix expressions to 
//Algorithm: Process each character: push operands to the stack, 
//pop for operators, evaluate, and push the result. 
//Final result is the only value on the stack.

int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  int result; // results for boxes 1 & 2


  while (expression[i] != '\0') // til the end of the expression
    {
     try
       {
	 item = expression[i];  // current char

  // ** do all the steps in the algorithm given in Notes-2A
  
/*if it is an operand (number), 
		 push it (you might get Overflow exception)*/

   if (item != '+' && item != '*' && item != '-') {
    postfixstack.push(item-'0');
   }

  /*else if it is an operator,
    pop the two operands (you might get Underflow exception), and
    apply the operator to the two operands, and
    push the result.*/

   else {
      
      postfixstack.pop(box2);  // pop the second operand
      postfixstack.pop(box1);  // pop the first operand

       if (item == '+') {
        result = box1 + box2;
      }
      else if (item == '*') {
        result = box1 * box2;
      }
      else if (item == '-') {
        result = box1 - box2;
      }

      postfixstack.push(result); //push result into postfixstack
      
   }
   
   // ** do all the steps in the algorithm given in Notes-2A
	 
	 
       } // this closes try
     
      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{cout<<"Overflow. Too many operands."; }
      catch (stack::Underflow)
	{cout<<"Underflow. Too few operands."; }
      catch (char const* errormsg ) // for invalid item case
	{cout<<"Invalid items detected"; }

      // go back to the loop after incrementing i
      i++;

    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
   if (!postfixstack.isEmpty()) {
  postfixstack.topElem(result); // Get the final result
  cout << "The result is: " << result << endl;
  postfixstack.pop(result); // Pop the final result


 // If anything is left on the stack, an incomplete expression 
 // was found so also inform the user.
  if (!postfixstack.isEmpty()) {
    cout << "Incomplete expression detected." << endl;
  }
  
  
}
  
}// end of the program
