/*
 * Chapter 2
 * Paragraph 4
 *
 * Counting sort algorithm usage
 */

#include <iostream>
#include "counting_sort.h"

#define DIM 100

using namespace std;

int main() {
  int a[DIM];
  for (int i=0; i<DIM; i++)
    a[i] = DIM-i;

  counting_sort(a, DIM, DIM);

  for (int i=0; i<DIM; i++)
    cout << a[i] << " ";
  cout << endl;

  return 0;
}
