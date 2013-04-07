#include "binarysearch.h"

#include<cstdlib>
#include<ctime>
#include<cassert>
#include<algorithm>

#define DIM 100000

int main()
{
  int A[DIM];

  std::srand(time(NULL));
  for (int i=0; i<DIM; i++)
  {
    int t = rand() % DIM;
    A[i] = t;
  }

  int v = A[rand() % DIM];

  std::sort(A, A+DIM);
  int v_idx = binarysearch(A, v, 0, DIM-1);
  assert(v == A[v_idx]);

  v_idx = binarysearch(A, -100, 0, DIM-1);  // not found
  assert(v_idx == -1);

  v_idx = binarysearch(A, DIM+1, 0, DIM-1);  // not found
  assert(v_idx == -1);

  return 0;
}
