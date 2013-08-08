/*
 * Chapter 1
 * Paragraph 1
 *
 * Iterativebinarysearch algorithm usage
 */

#include <iostream>
#include "iterativebinarysearch.h"

using namespace std;

int main()
{
  int A[] = {-20, 2, 4, 9, 34, 42, 67, 234};
  cout << iterativebinarysearch(A, 8, 4) << endl;
  cout << iterativebinarysearch(A, 8, -20) << endl;
  cout << iterativebinarysearch(A, 8, 234) << endl;
  return 0;
}
