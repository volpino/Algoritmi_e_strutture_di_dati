/*
 * Chapter 17
 * Paragraph 1
 *
 * Selection algorithm
 */

#include <iostream>
#include <cstdlib>

using namespace std;

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
T selezione(T A[], int primo, int ultimo, int k) {
  if (primo == ultimo) {
    return A[primo];
  }

  // to enforce randomness
  int rnd = rand() % (ultimo - primo + 1) + primo ;
  T tmp = A[rnd];
  A[rnd] = A[primo];
  A[primo] = tmp;

  int j = perno(A, primo, ultimo);
  int q = j - primo + 1;
  if (k <= q) {
    return selezione(A, primo, j, k);
  }
  else {
    return selezione(A, j+1, ultimo, k-q);
  }
}


int main() {
  int array[] = {3, 4, 1, 2, 9, 7, 6, 5, 8};
  cout << "Min: " << selezione(array, 0, 8, 1) << endl;
  cout << "Max: " << selezione(array, 0, 8, 9) << endl;
  cout << "Mediana: " << selezione(array, 0, 8, 5) << endl;
  return 0;
}
