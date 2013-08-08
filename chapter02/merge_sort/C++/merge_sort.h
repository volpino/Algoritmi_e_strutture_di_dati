/*
 * Chapter 2
 * Paragraph 3
 *
 * Merge sort algorithm implementation
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

template <class T>
void merge(T A[], int first, int last, int m)
{
  int i, j, k;
  //This can be optimized allocating support vector B outside merge function
  //and passing it as parameter
  T* B;
  B = new T[last+1];
  i = first;
  j = m+1;
  k = first;
  while (i<=m && j<=last)
  {
    if (A[i] <= A[j])
    {
      B[k] = A[i];
      i ++;
    }
    else
    {
      B[k] = A[j];
      j ++;
    }
    k ++;
  }
  j = last;
  for (int h=m; h>=i; h--)
  {
    A[j] = A[h];
    j --;
  }
  for (j=first; j<k; j++)
    A[j] = B[j];
  delete[] B;
}

template <class T>
void merge_sort(T A[], int first, int last)
{
  if (first<last)
  {
    int m = (first+last) / 2;
    merge_sort(A, first, m);
    merge_sort(A, m+1, last);
    merge(A,first,last,m);
  }
}

#endif
