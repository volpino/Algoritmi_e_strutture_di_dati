/*
 * Chapter 12
 * Paragraph 2
 *
 * QuickSort algorithm implementation
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H


template <class T>
int perno(T A[], int primo, int ultimo) {
  T x = A[primo];
  int j = primo;

  for (int i=primo; i<=ultimo; i++) {
    if (A[i] < x) {
      j++;
      T tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  A[primo] = A[j];
  A[j] = x;
  return j;
};

template <class T>
void quicksort_rec(T A[], int primo, int ultimo) {
  if (primo < ultimo) {
    int j = perno(A, primo, ultimo);
    quicksort_rec(A, primo, j-1);
    quicksort_rec(A, j+1, ultimo);
  }
};

template <class T>
void quicksort(T A[], int n) {
  quicksort_rec(A, 0, n-1);
};

#endif
