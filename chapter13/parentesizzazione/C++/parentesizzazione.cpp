/*
 *
 * Chapter 13
 * Paragraph 3
 *
 */

#include <iostream>
#include <climits>

#define MAX_N 100

using namespace std;

int M[MAX_N+1][MAX_N+1];
int S[MAX_N+1][MAX_N+1];

void parentesizzazione(int c[], int n)
{
  int i,j,h,k,t;

  for (i=1; i<=n; i++)
    M[i][i] = 0;
  for (h=2; h<=n; h++)
  {
    for (i=1; i<=n-h+1; i++)
    {
      j = i+h-1;
      M[i][j] = INT_MAX;
      for (k=i; k<=j-1; k++)
      {
        t = M[i][k]+M[k+1][j]+c[i-1]*c[k]*c[j];
        if (t<M[i][j])
        {
          M[i][j] = t;
          S[i][j] = k;
        }
      }
    }
  }
}

void stampaPar(int i, int j)
{
  if (i==j)
  {
    cout << "A[" << i << "]";
  }
  else
  {
    cout << "(";
    stampaPar(i,S[i][j]);
    cout << "*";
    stampaPar(S[i][j]+1,j);
    cout << ")";
  }
}

int main()
{
  int n = 5;
  int c[] = {3, 3, 1, 5, 7, 2};

  parentesizzazione(c, n);
  cout << "Parentesizzazione ottima di costo " << M[1][n] << ":\n";
  stampaPar(1,n);
  cout << endl;

  return 0;
}
