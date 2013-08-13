/*
 * Chapter 15
 * Paragraph 1
 */

#ifndef SHELL_SORT_H
#define SHELL_SORT_H

template <class T>
void shell_sort(T A[], int n)
{
  int h = 1;
  while (h<=n)
  {
    h = 3*h + 1;
  }
  h = h/3;
  while (h>=1)
  {
    for (int i=h+1; i<=n; i++)
    {
      T temp = A[i-1];
      int j = i;
      while (j>h && A[j-h-1]>temp)
      {
        A[j-1] = A[j-h-1];
        j = j - h;
      }
      A[j-1] = temp;
    }
    h = h/3;
  }
}

#endif
