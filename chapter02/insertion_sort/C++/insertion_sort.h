/*
 * Chapter 2
 * Paragraph 3
 *
 * Insertion sort algorithm implementation
 */

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

template <class T>
void insertion_sort(T A[], int n) {
  for (int i=1; i<n; i++) {
    T temp = A[i];
    int j = i;
    while (j>0 && A[j-1] > temp) {
      A[j] = A[j-1];
      j = j-1;
    }
    A[j] = temp;
  }
}

#endif
