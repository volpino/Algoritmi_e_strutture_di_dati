/*
 * Chapter 2
 * Paragraph 3
 *
 * Merge sort algorithm usage
 */

#include <iostream>
#include "merge_sort.h"

#define DIM 100

using namespace std;

int main()
{
  int a[DIM];
  for (int i=0; i<DIM; i++)
    a[i] = DIM-i;
  merge_sort(a,0,DIM-1);
  for (int i=0; i<DIM; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
