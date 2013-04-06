/*
 * Chapter 2
 * Paragraph 3
 *
 * Selection sort algorithm usage
 */

#include <iostream>
#include "selection_sort.h"

using namespace std;

const int dim = 100;

int main()
{
  int a[dim];
  for (int i=0; i<dim; i++)
    a[i] = dim-i;
  selection_sort(a,dim);
  for (int i=0; i<dim; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
