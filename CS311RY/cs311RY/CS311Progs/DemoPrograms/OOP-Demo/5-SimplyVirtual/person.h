// CS311 Yoshii - person header with a virtual doit
// ------------------------------------------------
using namespace std;

#include <string>

class person
{
 protected:
  string name;
  int age;

 public:
  person();
  ~person();
  virtual  void doit();  // virtual doit 

};
