/*
 *
 */

#include <iostream>

#include "merge_sort.h"

const int dim = 100;

using namespace std;

int main()
{
  int a[dim];
  for (int i=0; i<dim; i++)
    a[i] = dim-i;
  merge_sort(a,0,dim-1);
  for (int i=0; i<dim; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
