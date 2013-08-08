/*
 * Chapter 2
 * Paragraph 3
 *
 * Insertion sort algorithm usage
 */

#include <iostream>
#include "insertion_sort.h"

#define DIM 100

using namespace std;

int main() {
  int a[DIM];
  for (int i=0; i<DIM; i++)
    a[i] = DIM-i;

  insertion_sort(a, DIM);

  for (int i=0; i<DIM; i++)
    cout << a[i] << " ";
  cout << endl;

  return 0;
}
