#include <string>
#include <iostream>

#define DIM 10000

using namespace std;

int D[DIM];

int stringMatching(string P, string T) {
  for (int j=0; j<=T.size(); j++) D[j] = 0;

  for (int i=1; i<=P.size(); i++) {
    int dx = i-1;
    for (int j=1; j<=T.size(); j++) {
      int t = min(min(dx + (P[i-1] == T[j-1] ? 0 : 1), D[j] + 1), D[j-1] + 1);

      dx = D[j];
      D[j] = t;
    }
    D[0] = i;
  }

  int minimo = D[0];
  for (int i=1; i<=T.size(); i++) {
    cout << D[i] << endl;
    minimo = min(minimo, D[i]);
  }

  return minimo;
}


int main() {
  string pattern("pippo");
  string text("pappa");

  cout << "Result: " << stringMatching(pattern, text) << endl;
}
