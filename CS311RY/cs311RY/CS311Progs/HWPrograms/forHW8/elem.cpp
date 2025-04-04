// CS311 Yoshii SUM24 - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// Edit ** parts
//  NEVER delete my comments!!
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
  id = -1;  // cannot be 0 because 0 is a valid id
  key=""; // initialize other parts to be blanks
  mode="";
  bpm=0;
}

// initializing constructor to create an el_t object using arguments
el_t::el_t(int aid, string akey, string amode, int abpm)
{
  id = aid;
  key= akey; //  initialize other parts to be the arguments
  mode = amode;
  bpm = abpm;
}

// ONLY the id part should be available to the user of this class
int el_t::getid()
{
  return id;
}

// ONLY the id part should be available to the user of this class 
void el_t::setid(int aid)
{
  id = aid;
}

// Getter for the key part
string el_t::getKey()
{
    return key;
}

// Setter for the key part
void el_t::setKey(string akey)
{
    key = akey;
}

// Getter for the mode part
string el_t::getMode()
{
    return mode;
}

// Setter for the mode part
void el_t::setMode(string amode)
{
    mode = amode;
}

// Getter for the bpm part
int el_t::getBpm()
{
    return bpm;
}

// Setter for the bpm part
void el_t::setBpm(int abpm)
{
    bpm = abpm;
}

  
// overload == for search based on the id part only
bool el_t::operator==(el_t OtherOne)
{
  if (this->id == OtherOne.id) return true; else return false;
}

// based on the id part only
bool el_t::operator!=(el_t OtherOne)
{
  if (this->id != OtherOne.id) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.id << " " << E.key << " " << E.mode << " " << E.bpm;// display other parts of E in a nice way
  return os;  
}  
// if you make it come out just like the input file, Saving to a file will
// be easier!
