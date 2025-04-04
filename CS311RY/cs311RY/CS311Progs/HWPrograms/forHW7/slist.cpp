// CS311 Yoshii SUM24 slist.cpp
// Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Aiman Madan
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{ 
  
}

// positions always start at 1

// don't forget to return the position (>=1) or 0 if not found
int slist::search(el_t key){
  Node* P = Front;
  int pos = 1;
  while (P != NULL) {
    if (P->Elem == key) {
      return pos;
    }
    P = P->Next;
    pos++;
  }
  return 0; // not found
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
void slist::replace(el_t element, int pos){
  if (pos < 1 || pos > Count) {
    throw OutOfRange();
  }
  Node* P = Front;
  moveTo(pos, P);
  P->Elem = element;
}

bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false immediately
  // if the same lengths,
  //check each node to see if the elements are the same
  if (this->Count != OtherOne.Count) {
    return false;
  }
  Node* P1 = this->Front;
  Node* P2 = OtherOne.Front;
  while (P1 != NULL) {
    if (P1->Elem != P2->Elem) {
      return false;
    }
    P1 = P1->Next;
    P2 = P2->Next;
  }
  return true;
}
