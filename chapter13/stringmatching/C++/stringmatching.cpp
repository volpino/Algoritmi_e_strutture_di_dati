#include <string>
#include <iostream>

#define DIM 10000

using namespace std;

int D[DIM][DIM];

int stringMatching(string P, string T) {
  for (int i=1; i<=P.size(); i++) D[i][0] = i;
  for (int j=0; j<=T.size(); j++) D[0][j] = 0;

  for (int i=1; i<=P.size(); i++) {
    for (int j=1; j<=T.size(); j++) {
      int t = D[i-1][j-1] + (P[i-1] == T[j-1] ? 0 : 1);

      t = min(t, D[i-1][j] + 1);
      t = min(t, D[i][j-1] + 1);

      D[i][j] = t;
    }
  }

  int minimo = D[P.size()][0];
  int pos = 0;

  for (int j=1; j<=T.size(); j++) {
    if (D[P.size()][j] < minimo) {
      minimo = D[P.size()][j];
      pos = j;
    }
  }

  return pos;
}


int main() {
  string pattern("pippo");
  string text("quel lippo pippa di pippo ippo");

  cout << "Result: " << stringMatching(pattern, text) << endl;
}
