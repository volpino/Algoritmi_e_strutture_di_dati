/*
 * Chapter 2
 * Paragraph 3
 *
 * Selection sort algorithm usage
 */

#include <iostream>
#include "selection_sort.h"

#define DIM 100

using namespace std;

int main()
{
  int a[DIM];
  for (int i=0; i<DIM; i++)
    a[i] = DIM-i;
  selection_sort(a,DIM);
  for (int i=0; i<DIM; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
