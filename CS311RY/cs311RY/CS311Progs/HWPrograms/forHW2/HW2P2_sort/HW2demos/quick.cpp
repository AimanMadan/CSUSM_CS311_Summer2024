// CS311 Quick Sort - plug in your partition and it should work
//---------------------------------------------------------------

#include<iostream>
using namespace std;

// partitions the array a into smaller than pivot and others.
int partition(int a[], int f, int r)
{
cout << ".. Partition called with " << "front " << f << " and rear " << r << endl;
// ** your partition here but it needs to
// ** set the pivot to a[0] at the start
  int pivot = a[f];  // pivot is the first element
  int small = f; // small pointer from the left
  int large = r; // large pointer from the right 

  while (small <= large)//until they cross
    {
      // loop for finding out-of-place pairs and swap them
      //    until the small and large cross
      // you will be checking a[small] and a[large] against pivot
       while (a[small] < pivot){
          small++;
      }
       while (a[large] > pivot){
          large--;
      }
      //    if both are bad (and not crossed yet), swap and then move
      //    if a[small] is OK, move small
      //    if a[large] is OK, move large
      
      if (small <= large) {
          swap(a[small], a[large]);
          small++;
          large--;
      }
    }//end of while

   // return the partition point where
   // those smaller than pivot are before what is returned
   // there is a special cases (small is at the beginning)
   // and a regular case
      return small;
}


// sorting a's section starting at f and ending at r
void quicksort(int a[], int f, int r)
{
  if (f >= r) return;

  cout << "QuickSort front is " << f << " and rear is " << r << endl;

  int beg = partition(a, f, r);

  quicksort(a, f, beg-1);  // sort the small section in place
  quicksort(a, beg, r);    // sort the large section in place
}


int main()
{
  int x;
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  quicksort(nums, 0, x-1);

  cout << "FINAL RESULT:" << endl;
  for (int i = 0; i < x; i++) // up to the partition
      {cout << nums[i]; }
  cout << endl;
}
