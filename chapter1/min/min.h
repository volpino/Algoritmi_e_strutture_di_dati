/*
 * Chapter 1
 * Paragraph 1
 *
 * Min algorithm implementation
 */

#ifndef MIN_H
#define MIN_H

template <class T>
T min(T A[], int n) {
  if (n <= 0)
    return -1;

  T min_value = A[0];
  for (int i=1; i<n; i++) {
    if (A[i] < min_value)
      min_value = A[i];
  }

  return min_value;
}

#endif
