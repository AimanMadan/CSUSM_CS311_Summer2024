// CS311 YOSHII el_t functions for the Graph Class 

#include "elem.h"

// blank element
el_t::el_t()
{
  name = ' ';
  weight = 0;
}

// initialized element
el_t::el_t(char aname, int w)
{
  name = aname;
  weight = w;
}

// Access functions
char el_t::getname()
{ return name; }
int el_t::getweight()
{ return weight; }


// This overloads cout for the el_t object
friend ostream& operator<<(ostream& o, const el_t& E)
{
  o << E.name << "+" << E.weight;
}

// This overloads == for the el_t object
// Two graph vertices are the same if they have
// the same name.
bool el_t::operator==(el_t OtherOne)
{
  if (this->name == OtherOne.name) return true; else return false;
}
