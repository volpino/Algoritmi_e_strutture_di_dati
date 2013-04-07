/*
 * Chapter 2
 * Paragraph 1
 *
 * Binarysearch algorithm usage
 */


#include <iostream>
#include "binarysearch.h"

using namespace std;

int main()
{
  int A[] = {-20, 2, 4, 9, 34, 42, 67, 234};
  cout << binarysearch(A, 4, 0, 8) << endl;
  cout << binarysearch(A, -20, 0, 8) << endl;
  cout << binarysearch(A, 234, 0, 8) << endl;
  return 0;
}
