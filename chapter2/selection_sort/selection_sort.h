/*
 * Chapter 2
 * Paragraph 3
 *
 * Selection sort algorithm implementation
 */

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H


template <class T>
void swap(T& a, T& b)
{
  T t = a;
  a = b;
  b = t;
}

template <class T>
int min(T A[], int k, int n)
{
  int min = k;
  for (int h=k+1; h<n; h++)
    if (A[h] < A[min])
      min = h;
  return min;
}

template <class T>
void selection_sort(T A[], int n)
{
  for (int i=0; i<n; i++)
  {
    int j = min(A, i, n);
    swap(A[i],A[j]);
  }
}

#endif
