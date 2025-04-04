// CS311 Yoshii HW5 client to test the Pqueue
// Use as is! DO NOT CHANGE!!!! 

#include "pqueue.h"

int main()
{
  pqueue Jobs;

  Jobs.insertjob(20);
  Jobs.insertjob(12);
  Jobs.displayAll();
  Jobs.insertjob(30);
  Jobs.insertjob(1);
  Jobs.displayAll();
  Jobs.insertjob(5);
  Jobs.insertjob(6);
  Jobs.insertjob(7);
  Jobs.insertjob(8);
  Jobs.insertjob(9);
  Jobs.insertjob(10);
  Jobs.insertjob(11);
  Jobs.displayAll();

  Jobs.insertjob(50); // error message

  Jobs.printjob();
  Jobs.displayAll();
  Jobs.printjob();
  Jobs.displayAll();
  Jobs.printjob();
  Jobs.displayAll();
  Jobs.printjob();
  Jobs.displayAll();

  Jobs.insertjob(2);
  Jobs.displayAll();
  Jobs.insertjob(3);
  Jobs.displayAll();
}  
