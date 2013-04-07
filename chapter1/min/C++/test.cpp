#include "min.h"

#include<cstdlib>
#include<ctime>
#include<cassert>
#include<algorithm>

#define DIM 1000

int main()
{
  int A[DIM];
  int min_A;

  std::srand(time(NULL));
  for (int i=0; i<DIM; i++)
  {
    int t = rand();
    A[i] = t;
  }

  min_A = min(A, DIM);
  std::sort(A, A+DIM);
  assert(min_A == A[0]);

  return 0;
}
