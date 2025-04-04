// CS311 Yoshii - person header with virtual doit
// ---------------------------------------------
#ifndef PPP
#define PPP

using namespace std;
#include <string>

// This is the parent class
class person
{
   protected:
    string name;
    int age;

 public:
    person();
    ~person();
  virtual void doit();   

};



#endif
