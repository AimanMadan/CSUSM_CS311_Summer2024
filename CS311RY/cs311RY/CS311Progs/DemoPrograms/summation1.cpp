#include<iostream>
#include<cmath>
using namespace std;

int main()
{ int N, sum;
  cout << "This program sums K as K varies from 0 to the upper bound N" << endl;
  cout << "Enter the upper bound N: ";
  cin  >> N;

  for (int K = 0; K <=N; K++)
    { cout << ".. adding " << K << endl;
      sum = sum + K; }

  cout << "Sum is " << sum << endl;
}
