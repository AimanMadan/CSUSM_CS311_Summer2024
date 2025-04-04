// CS311 Yoshii - girl header inheriting from person
// ---------------------------------------------------
#include "person.h"
using namespace std;

class girl : public person
{
 private: 
   int g_id;

 public:
  girl();
  ~girl();
  void doit();  // girl's doit

}; 
