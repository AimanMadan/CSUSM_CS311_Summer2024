#include<iostream>
#include<cmath>
using namespace std;

int main()
{ int N, sum;
  cout << "This program sums 2^K as K varies from 0 to the upper bound N" << endl;
  cout << "Enter the upper bound N: ";
  cin  >> N;

  for (int K = 0; K <=N; K++)
    { cout << ".. adding 2^" << K << endl;
      sum = sum + pow(2, K); }

  cout << "Sum is " << sum << endl;
}
