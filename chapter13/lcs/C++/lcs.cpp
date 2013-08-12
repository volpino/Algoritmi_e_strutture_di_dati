/*
 *
 * Chapter 13
 * Paragraph 7
 *
 */

#include <iostream>
#include <algorithm>

#define MAX_L 100

using namespace std;

int D[MAX_L+1][MAX_L+1];

template <class Item>
int lcs(const Item P[], const Item T[], int i, int j)
{
  if (i==0 || j==0)
    return 0;
  if (D[i][j] == -1)
  {
    if (P[i-1] == T[j-1])
      D[i][j] = lcs(P,T,i-1,j-1) + 1;
    else
      D[i][j] = max(lcs(P,T,i-1,j),lcs(P,T,i,j-1));
  }
  return D[i][j];
}

int main()
{
  int n,m;
  n = 9;
  const char *p = "aaabbbccc";
  m = 7;
  const char *t = "dadfbcf";

  for (int i=0; i<=n; i++)
    for (int j=0; j<=m; j++)
      D[i][j] = -1;

  cout << "La sottosequenza comune massimale è lunga:\n";
  cout << lcs(p, t, n, m) << endl;
  return 0;
}
