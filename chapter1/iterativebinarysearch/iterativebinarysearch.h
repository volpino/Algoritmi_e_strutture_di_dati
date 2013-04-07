/*
 * Chapter 1
 * Paragraph 1
 *
 * Iterativebinarysearch algorithm implementation
 */

#ifndef ITERATIVEBINARYSEARCH_H
#define ITERATIVEBINARYSEARCH_H

template <class T>
T iterativebinarysearch(T A[], int n, T v) {
  int i = 0;
  int j = n - 1;
  int m = (i + j) / 2;  // integer division

  while (i < j && A[m] != v) {
    if (A[m] < v)
      i = m + 1;
    else
      j = m - 1;
    m = (i + j) / 2;  // integer division
  }

  if (i > j || A[m] != v)
    return -1;
  return m;
}

#endif
