// For the Graph class:
// element type of a list node is defined
// el_t changed by the client to fit the needs

#ifndef A
#define A

#include <iostream>
#include <string>
using namespace std;

class el_t
{
  private:
  char name;  // vertex name
  int weight;  // edge weight

  public:

  // constructors
  el_t();   
  el_t(char, int);  // el_t M('A', 20);

  // access functions
  char getname();    // E.getname();
  int  getweight(); // E.getweight();

  // overload == and cout
  bool operator==(el_t);
  friend ostream& operator<<(ostream& , const el_t& );

};

#endif
