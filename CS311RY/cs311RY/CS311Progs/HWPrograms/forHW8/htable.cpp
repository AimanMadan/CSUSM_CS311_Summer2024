// CS311 Yoshii SUM24 - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for id
// so that it would work even if each element in the hash table changed
//  NEVER delete my comments!!
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Aiman Madan
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"
#include "elem.h" 

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int id)
{ return id % TSIZE; }

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int slot = hash(element.getid());  // hash with the id part
  table[slot].addRear(element); // Note that this means adding the element to a slist in the slot (call addRear)
  return slot;
}

// finds element using the sid and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int sid)
{ 
 int slot = hash(sid); // hash with sid
 el_t selement;  // this is the element to look for in slist
  selement.setid(sid); // initialize selement with just the sid (call setid)
 el_t foundElement = table[slot].search2(selement); // call slist's search2 with selement which returns the found element 
 return foundElement; // return the found element from here (it could be blank but that's OK)
}

// finds the element given the id  and deletes it from the table.
//  Returns the slot number.
int htable::deleteIt(int id)
{
 int slot = hash(id); // hash with sid
 el_t selement;  // this is the element to look for in slist
 selement.setid(id); //  initialize selement with just the sid
   //  call slist's search which gives you the location I and then call deleteIth
  int position = table[slot].search(selement);
  if (position != 0) {
        table[slot].deleteIth(position, selement);
  }
  return slot; //  return the slot number
}

// fills the table using the specified input file 
void htable::fillTable(istream& fin)
{ int aid;
  string akey, amode;
  int abpm;
  //  Model this after HW6 to get data from the file the user specified
  //  Which elem and slist functions do you call? List them here first.
  while (fin >> aid >> akey >> amode >> abpm) // while reading is OK
  { 
    // fin other parts and create an element object
    el_t element(aid, akey, amode, abpm); // create a new element with the parts
    // You can call the add function to add the created element to the table
    add(element);
  }
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < TSIZE; i++)
    { cout << i << ":" ;   
      table[i].displayAll(); // call slist's displayAll 
    }
}

// saves into the specified file in the same format as the input file
void htable::saveTable(ostream& fout) 
{
    // For each non-empty slot of the table, retrieve the slist to a local variable
    for (int i = 0; i < TSIZE; i++) {
        if (!table[i].isEmpty()) {
            Node* current = table[i].Front;  
            while (current != nullptr) {
                // fout each removed element.
                fout << current->Elem.getid() << " "
                     << current->Elem.getKey() << " "
                     << current->Elem.getMode() << " "
                     << current->Elem.getBpm() << endl;
                current = current->Next;
            }
        }
    }
}