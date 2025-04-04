// CS311 Yoshii - girl implementation
// ----------------------------------------
#include "girl.h"
#include <iostream>

girl::girl()
{ g = 3; cout << "girl const" << endl; }

girl::~girl()
{ cout << "girl deconst" << endl; }

// defining the inherited virtual function here
void girl::doit()
{ cout << "I am a girl." << endl; }
