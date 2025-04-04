// CS311 Yoshii - girl header that inherits from Ipure
// --------------------------------------------------
#include "Ipure.h"
using namespace std;

class girl : public Ipure
{
 private: int g;

 public:
  girl();
  ~girl();
  void doit();  // need to declare doit here and define doit.   
}; 
