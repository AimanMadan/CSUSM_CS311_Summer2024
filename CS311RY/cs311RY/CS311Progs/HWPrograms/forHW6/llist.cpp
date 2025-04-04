//CS311 Yoshii SUM24 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Aiman Madan
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ 
  cout << "... in llist constructor..." << endl; 
  Front = Rear = NULL; //initialize Front and Rear to be NULL 
  Count = 0; 
}

llist::~llist()
{ 
  cout << ".... in llist destructor..." << endl;
  el_t temp;
  //while the list is not empty, call deleteFront repeatedly to delete all nodes
  while (!isEmpty()) {
    deleteFront(temp);
  }
}

//PURPOSE: Checks if the list is empty
//PARAMETER: None
bool llist::isEmpty()
{ 
  //return true if Front and Rear are both pointing to NULL and Count is 0
  return (Front == NULL && Rear == NULL && Count == 0);
} // be sure to check all 3 data members

//PURPOSE: Displays all elements in the list
//PARAMETER: None
void llist::displayAll()
{
  //special case: if the list is empty, display [ empty ] 
  if (isEmpty()) {
    cout << "[ empty ]" << endl;
  }
  else {
    Node *P = Front;
    cout << "[ "; 
    while (P != NULL)
    {
      cout << P->Elem << " ";
      P = P->Next;
    }
    cout << "]" << endl;
  }
}  // be sure to display horizontally in [ ] with blanks between elements e.g. [ 1 2 3 4 ]

//PURPOSE: Adds a new element to the rear of the list
//PARAMETER: NewNum - the element to add
void llist::addRear(el_t NewNum)
{
  if (isEmpty()) { // special case: if this is going to be the very first node
    Node *newNode = new Node; //create a new node 
    newNode->Elem = NewNum; 
    newNode->Next = NULL; 
    Front = Rear = newNode; 
    Count++; //update count
  }
  else { // regular case: add a new node at the rear
    Node *newNode = new Node;
    newNode->Elem = NewNum;
    newNode->Next = NULL;
    Rear->Next = newNode;
    Rear = newNode;
    Count++;
  }
} // comment the 2 cases

//PURPOSE: Adds a new element to the front of the list
//PARAMETER: NewNum - the element to add
void llist::addFront(el_t NewNum)
{
  if (isEmpty()) { // special case: if this is going to be the very first node
    Node *newNode = new Node;
    newNode->Elem = NewNum;
    newNode->Next = NULL;
    Front = Rear = newNode; 
    Count++;
  }
  else { // regular case: add a new node at the front
    Node *newNode = new Node;
    newNode->Elem = NewNum;
    newNode->Next = Front;
    Front = newNode;
    Count++;
  }
} // comment the 2 cases

//PURPOSE: Deletes the front element of the list
//PARAMETER: OldNum - the element to be deleted (by reference)
void llist::deleteFront(el_t& OldNum)
{ 
  if (isEmpty()) { // Error case: if the List is empty, throw an exception
    throw Underflow();
  }
  else if (Front == Rear) { // special case: if this is going to make the list empty (If there is one element)
    OldNum = Front->Elem;
    delete Front;
    Front = Rear = NULL;
    Count = 0; 
  }
  else { // regular case: remove the front node
    OldNum = Front->Elem;
    Node *Second = Front->Next;
    delete Front;
    Front = Second;
    Count--;
  }
} // comment the 3 cases

//PURPOSE: Deletes the rear element of the list
//PARAMETER: OldNum - the element to be deleted (by reference)
void llist::deleteRear(el_t& OldNum)
{
  if (isEmpty()) { // Error case: if the List is empty, throw an exception
    throw Underflow();
  }
  else if (Front == Rear) { // special case: if this is going to make the list empty
    OldNum = Rear->Elem;
    delete Rear;
    Front = Rear = NULL;
    Count = 0; 
  }
  else { // regular case: remove the rear node
    OldNum = Rear->Elem;
    Node *P = Front;
    while (P->Next != Rear) {
      P = P->Next;
    }
    delete Rear;
    Rear = P;
    Rear->Next = NULL;
    Count--;
  }
} // comment the 3 cases

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{  // Note that case1 client does not test this. But it is neede
   // for case 2 so make it work perfectly.  
 
  // moves temp J-1 times to go to the Jth node (>=1 and <= Count is assumed)   
  // for ( int K = ... ) temp = temp->Next;
  for (int K = 1; K < J; K++) {
    temp = temp->Next;
  }
}


/* --- harder ones for case 2 and 3 follow --- */


//PURPOSE: Delets an element at the I-th position in the list
//PARAMETER: I - the position to delete at, OldNum - the element to delete
void llist::deleteIth(int I, el_t& OldNum)
{
  // Error case: If I is an illegal value (i.e. > Count or < 1) throw an exception
  if (I < 1 || I > Count) { 
    throw OutOfRange();
  }
  else if (I == 1) { // Special case: this should simply call deleteFront (I = 1)
    deleteFront(OldNum);
  }
  else if (I == Count) { // Special case: this should simply call deleteRear (I == Count)
    deleteRear(OldNum);
  }
  else { // Regular case: will delete the Ith node (I starts out at 1)
    Node *P = Front;
    moveTo(I - 1, P); // go to the I-1th node
    Node *temp = P->Next; 
    OldNum = temp->Elem; 
    P->Next = temp->Next; 
    delete temp; 
    Count--; 
  }
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE: Inserts an element at the I-th position in the list
//PARAMETER: I - the position to insert at, newNum - the element to insert
void llist::insertIth(int I, el_t newNum)
{
  if (I < 1 || I > (Count + 1)) { // Error case: If I is an illegal value (i.e. > Count + 1 or < 1) throw an exception
    throw OutOfRange();
  }
  else if (I == 1) { // Special case: this should simply call addFront (I == 1)
    addFront(newNum);
  }
  else if (I == Count + 1) { // Special case: this should simply call addRear (I == Count + 1)
    addRear(newNum);
  }
  else { // Regular case: will insert the newNum at the Ith position (I starts out at 1)
    Node *P = Front;
    moveTo(I - 1, P); // go to the I-1th node
    Node *newNode = new Node; 
    newNode->Elem = newNum; 
    newNode->Next = P->Next; 
    P->Next = newNode; 
    Count++; 
  }
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: Copy Constructor to allow pass by value and return by value of a llist
//PARAMETER: Original - the list to copy from
llist::llist(const llist& Original)
{
  cout << "calling the llist copy constructor" << endl;
  Front = Rear = NULL; // initialize to empty
  Count = 0;

  Node *P = Original.Front; // P points to the Original's Front
  while (P != NULL) {
    addRear(P->Elem); // copy each node to the rear
    P = P->Next;
  }
} // use my code

//PURPOSE: Overloading of = (returns a reference to a llist)
//PARAMETER: OtherOne - the list to assign from
llist& llist::operator=(const llist& OtherOne)
{
  cout << "calling the llist operator=" << endl;
  if (&OtherOne != this) { // check for self-assignment
    // First, destroy this object's list
    el_t temp;
    while (!isEmpty()) {
      deleteFront(temp);
    }

    // Now copy from OtherOne
    Node *P = OtherOne.Front; // P points to the source's Front
    while (P != NULL) {
      addRear(P->Elem); // copy each node to the rear
      P = P->Next;
    }
  }
  return *this; // return self
} // use my code

