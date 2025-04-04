// CS311: BST header file for HW4 - by Yoshii - DO NOT CHANGE!!
// This BST has an Up link to make it easy to go up the tree later 
//------------------------------------------------------------

// tree element type is int for now
typedef int el_t;   // el_t is hidden from the client

// definition of what a Vertex is - also hidden from the client
struct Vertex
{
  Vertex *Up;  // points to the parent node 
  Vertex *Left;
  el_t  Elem;
  Vertex *Right;
  int Height;   // for EC 
  int Balance;  // for EC 
};   

// this is set up to be inherited by another class
class BST
{
  
 public:
  
  BST();  // intializes Root
  ~BST();  // destructor calls dtraverse to destroy the dynamic tree
  
  // PURPOSE: these will show the vertices in IN order 
  // TO CALL: No parameter  but provide a pointer to 
  //          the root vertex in calling INorderTraversal
  void Display();      
  void INorderTraversal(Vertex*); // recursive
  
  // PURPOSE: these will search in PRE order - same as Depth First
  // TO CALL: provide the element to search for; provide a pointer to 
  //          the root vertex in calling PREorderSearch
  bool Search(el_t);
  bool PREorderSearch(Vertex*, el_t); // recursive
  
  // PURPOSE: This adds a new vertex into the BST 
  // TO CALL: provide the element to be added to the tree
  void InsertVertex(el_t);
  
  // PURPOSE: This deletes a vertex with the given element 
  //     - calls remove and  findMax (see below)
  // TO CALL: provide the element to be removed from the tree
  void DeleteVertex(el_t);
  
  // the following can be inherited but not available to the client 
 protected:   

  Vertex *Root; //  Root which is a pointer to the root vertex

  // utility functions follow - these are not for the clients to use
  // These were created to implement the public methods
  
  void dtraverse(Vertex*);
  // traverse and delete all vertices in post order
  
  void remove(Vertex*, Vertex*); 
  // removes the vertex knowing its parent
  
  el_t findMax(Vertex*);  // finds the MAX element in the
  // left sub-tree of the vertex and also deletes it
  
  void climbup(Vertex* V);  
  // E.C function to compute height and balance factors
};


