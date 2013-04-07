/*
 * Chapter 2
 * Paragraph 4
 *
 * Counting sort algorithm implementation
 */

#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

template <class T>
void counting_sort(T A[], int n, int k) {
  int i, j;

  k += 1;
  int *B = new int[k];

  for (i=0; i<k; i++)
    B[i] = 0;

  for (i=0; i<n; i++)
    B[A[i]] += 1;

  j = 0;
  for (i=0; i<k; i++) {
    while (B[i] > 0) {
      A[j] = i;
      j += 1;
      B[i] -= 1;
    }
  }

  delete[] B;
}

#endif
