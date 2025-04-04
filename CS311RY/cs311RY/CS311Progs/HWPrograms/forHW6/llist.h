//CS311 Yoshii SUM24 llist.h
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Aiman Madan
// Compiler:  g++ 
// File type: header file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected: // changed to private 
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //A Function to check if the llist is empty
  bool isEmpty();
    
  //A Function to display all elements in the list
  void displayAll();

  // A Function to add an element to the front of the list
  void addFront(el_t);
    
  // A Function to add an element to the rear of the list
  void addRear(el_t);

  // A Function to delete an element from the front of the list
  void deleteFront(el_t&);
  
    
  // A Function to delete an element from the rear of the list
  void deleteRear(el_t&);

  //---------------------------------------


  // A Function to delete the ith element from the list
  void deleteIth(int, el_t&);  

  // A Function to insert an element at the ith position
  void insertIth(int, el_t); 

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //overloading of '=' will return a reference to a llist
  llist& operator=(const llist&); 


};