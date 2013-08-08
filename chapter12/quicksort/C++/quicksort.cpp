/*
 * Chapter 12
 * Paragraph 2
 *
 * QuickSort algorithm usage
 */

#include <iostream>
#include "quicksort.h"

#define DIM 100

using namespace std;

int main() {
  int a[DIM];
  for (int i=0; i<DIM; i++)
    a[i] = DIM-i;

  quicksort(a, DIM);

  for (int i=0; i<DIM; i++)
    cout << a[i] << " ";
  cout << endl;

  return 0;
}
