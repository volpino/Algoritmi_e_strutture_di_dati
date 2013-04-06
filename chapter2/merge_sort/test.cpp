#include "merge_sort.h"

#include<cstdlib>
#include<ctime>
#include<cassert>
#include<algorithm>

#define DIM 1000000

int main()
{
  int A[DIM];
  int B[DIM];

  std::srand(time(NULL));
  for (int i=0; i<DIM; i++)
  {
    int t = rand();
    A[i] = t;
    B[i] = t;
  }
  merge_sort(A,0,DIM-1);
  std::sort(B,B+DIM);
  for (int i=0; i<DIM; i++)
    assert(A[i] == B[i]);

  return 0;
}
