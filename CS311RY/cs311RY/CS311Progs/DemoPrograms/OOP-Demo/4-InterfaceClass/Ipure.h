// CS311 Yoshii - This is an abstract Interface class
// It has no data members and thus no constructor
// It has only pure virtual functions
// All clases derived from it must use the same functions
// and define them. The client can use any of these classes.
// --------------------------------------------------------
using namespace std;

class Ipure
{

 public:

   virtual  void doit() = 0;  // pure virtual function with no body

};
