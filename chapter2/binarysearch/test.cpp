#include "binarysearch.h"

#include<cstdlib>
#include<ctime>
#include<cassert>
#include<algorithm>

#define DIM 1000

int main()
{
  int A[DIM];

  std::srand(time(NULL));
  for (int i=0; i<DIM; i++)
  {
    int t = rand();
    A[i] = t;
  }

  int v = A[rand() % DIM];

  std::sort(A, A+DIM);
  int v_idx = binarysearch(A, v, 0, DIM);
  assert(v == A[v_idx]);

  return 0;
}
