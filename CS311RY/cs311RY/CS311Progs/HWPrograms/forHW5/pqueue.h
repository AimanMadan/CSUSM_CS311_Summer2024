// CS311 Yoshii
// - header file for priority printer queue HW5 
// - heaptree priority queue impleneted using an array
// DO NOT CHANGE!!!
// ---------------------------------------------

#include <iostream>
using namespace std;

int const MAX = 11;

class pqueue
{
  private:

  int Q[MAX];   // array holding jobs - only priority numbers are stored
  int count;   // how many jobs are in the array
               // jobs are in slots 0 through count-1

  // Utility functions
  void swap(int, int);
  void reheapify();  // reheapify after printing
      // - involves moving the last job to the front and trickling down
  int  getSmallerchild(int);  // return location of the smaller child
                  //- compares L and R children of the given location
  void trickleup();    // trickling up after adding at the rear
  int getParent(int);  // return the parent location given the child loc
  bool even(int);      // is the number even?  Needed to find the parent

public:
    pqueue();
    ~pqueue();
    void insertjob(int);  // supply the job priority number
    void printjob();      // print a job
    void displayAll();    // display all jobs

};
