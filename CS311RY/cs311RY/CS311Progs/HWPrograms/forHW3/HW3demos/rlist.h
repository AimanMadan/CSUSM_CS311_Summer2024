//  CS311 Linked Queue ADT - by Yoshii 
//  Header File  rlist.h
// Note that this has no overloading and no copy constructor and is not the same as the CS311 linked list.
//***********************************************************************

typedef int el_t;

// list node is defined here as a struct Node
struct Node
{
  el_t Elem;   // elem is the element stored
  Node   *Next;  // next is the pointer to the next node
};

class llist
{
  
 protected:
  
  Node *Front;       // front  pointer 
  Node *Rear;        // rear   pointer
  int  Count;        // counter for the number of elements
  
 public:
  
  class Underflow{};
  class OutOfRange {};
    
  llist ();                       // constructor  
  ~llist();                       // destructor
  
  bool isEmpty();
  void moveFront();    
  void displayAll();
    
  void addRear(el_t NewNum);
    
  void deleteFront(el_t& OldNum);
    
  void addFront(el_t NewNum);
    
  void deleteRear(el_t& OldNum);
    
  void deleteIth(int I, el_t& OldNum);
    
  void addbeforeIth(int I, el_t newNum);
    
};
