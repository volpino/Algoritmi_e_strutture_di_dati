/*
 * Chapter 13
 *
 * Tartaglia triangle
 */

#include <iostream>

using namespace std;

#define DIM 1000

long long C[DIM][DIM];


void tartaglia(int n) {
  for (int i=0; i<n; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
  }

  for (int i=2; i<n; i++) {
    for (int j=1; j<i; j++) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }
}


int main() {
  tartaglia(10);

  for (int i=0; i<10; i++) {
    for (int j=0; j<10; j++) {
      cout << "C(" << i << "," << j << ") = " << C[i][j] << endl;
    }
  }
}
