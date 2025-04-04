// CS311 Yoshii - boy header inheriting from person
// ---------------------------------------------------
#include "person.h"
using namespace std;


class boy : public person
{
 private: 
   int b_id;

 public:
  boy();
  ~boy();
  void doit();  // boy's doit
}; 
