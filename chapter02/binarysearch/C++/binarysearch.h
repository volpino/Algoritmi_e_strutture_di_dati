/*
 * Chapter 2
 * Paragraph 1
 *
 * Binarysearch algorithm implementation
 */

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

template <class T>
T binarysearch(T A[], T v, int i, int j) {
  if (i > j)
    return -1;

  int m = (i + j) / 2;  // integer division
  if (A[m] == v)
    return m;
  else if (A[m] < v)
    return binarysearch(A, v, m+1, j);
  else
    return binarysearch(A, v, i, m-1);
}

#endif
