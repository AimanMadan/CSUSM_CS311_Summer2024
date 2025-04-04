// CS311 Yoshii SUM24 - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// I use IFNDEF in case this file gets included more than once
// Update based on **
// ---------------------------------------------------------

#ifndef A
#define A

#include <iostream>
#include <string>
using namespace std;

class el_t {
  
 private:  // these will change depending
           // on the client needs
  int id;      // id -- for EC, key has to change to string everywhere!!!
  string key;  // The key to the songs ex. "C#", "D", "Eb", etc.
  string mode; // The mode of the songs minor or major
  int bpm; // The tempo of the songs
 

 public:

  el_t();  // to create a blank el_t object
  el_t(int, string, string, int); // to create an initialized el_t object - useful for the client   ** add more arguments to create the object

 // The following functions are available to
 // the htable class to be able to
 // use different el_t without modifying the code

  int getid(); // only the key part can be accessed by the user of this class.
  string getKey();
  string getMode();
  int getBpm();

  void setid(int); // only the key part can be accessed by the user of this class.
  void setKey(string);
  void setMode(string);
  void setBpm(int);

  // In linked list search,
  //    == is used to compare node elements
  // but what does it mean for this client to compare
  // node elements?  
  bool operator==(el_t);  // overload == for search
  bool operator!=(el_t);  // overload != for search

  // This overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  friend ostream& operator<<(ostream&, const el_t&);


};

#endif
  


