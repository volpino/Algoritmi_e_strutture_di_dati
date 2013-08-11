/*
 *
 * Chapter 13
 * Paragraph 3
 *
 */

public class Parentesizzazione {
  private final int MAX_N = 100;
  public int M[][] = new int[MAX_N+1][MAX_N+1];
  public int S[][] = new int[MAX_N+1][MAX_N+1];

  public void parentesizzazione(int c[], int n) {
    int i,j,h,k,t;

    for (i=1; i<=n; i++)
      M[i][i] = 0;
    for (h=2; h<=n; h++)
    {
      for (i=1; i<=n-h+1; i++)
      {
        j = i+h-1;
        M[i][j] = Integer.MAX_VALUE;
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

  public void stampaPar(int i, int j) {
    if (i==j)
    {
      System.out.print("A["+i+"]");
    }
    else
    {
      System.out.print("(");
      stampaPar(i,S[i][j]);
      System.out.print("*");
      stampaPar(S[i][j]+1,j);
      System.out.print(")");
    }
  }

  public static void main(String[] args) {
    int n = 5;
    int c[] = {3, 3, 1, 5, 7, 2};

    Parentesizzazione p = new Parentesizzazione();

    p.parentesizzazione(c, n);
    System.out.println("Parentesizzazione ottima di costo "+p.M[1][n]+":");
    p.stampaPar(1,n);
    System.out.println("");
  }
}