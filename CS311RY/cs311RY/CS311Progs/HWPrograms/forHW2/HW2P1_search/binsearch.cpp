using namespace std;
#include <iostream>

// CS311 YOSHII SUM24 binsearch.cpp
// The Algorithm is in Notes-4A so copy and paste it here!!!!!
// On Empress, control-rightclick will bring up the paste option.
// NEVER delete my comments!!!
//---------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Aiman Madan
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers 
// This recursive function returns the slot number in which x was found
// or -1
int binarySearch(int L[], int x, int first, int last) 
{
  int middle = (first + last) /2 ;
   // the mid is found... 
    cout << "comparing against an element in slot " << middle << endl;

  // The rest based on the notes to recurse
  if (x == L[middle]) 
    return middle; // found x at location middle, so return the location
  
  
  else if (x < L[middle])
   last = middle - 1; 	// go to first half

  else if (x > L[middle]) 
  first = middle + 1; 	// go to second half

 //  Be sure to check for first > last and
  //   first == last cases to
  //   end the recursion now
   if (first > last) 
    return -1; //x is not found
  

  return binarySearch(L, x, first, last);  // recursive call
}

int main()
{ int A[10];
  int e;  // to look for this

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A, e, 0, 9);

  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;

}
