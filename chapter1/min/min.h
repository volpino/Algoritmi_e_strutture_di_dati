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
  T min_value = A[1];
  for (int i=2; i<n; i++) {
    if (A[i] < min_value)
      min_value = A[i];
  }

  return min_value;
}

#endif
