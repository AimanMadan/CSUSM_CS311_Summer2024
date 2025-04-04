// CS311 Yoshii - this demonstrates how to generate random numbers

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
  cout << time(NULL);

  /* initialize random seed: */
  srand (time(NULL));

  for (int i=0; i < 10; i++) 
    {  /* generate secret number between 1 and 10: */
      cout <<  rand() % 10 + 1 <<endl; }

}
