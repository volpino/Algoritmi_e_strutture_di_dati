/*
 *
 * Chapter 13
 * Paragraph 7
 *
 */

public class Lcs {
  public final int MAX_L = 100;
  public int D[][] = new int[MAX_L+1][MAX_L+1];

  public <Item> int lcs(Item P[], Item T[], int i, int j) {
    if (i==0 || j==0)
      return 0;
    if (D[i][j] == -1)
    {
      if (P[i-1] == T[j-1])
        D[i][j] = lcs(P,T,i-1,j-1) + 1;
      else
        D[i][j] = Math.max(lcs(P,T,i-1,j),lcs(P,T,i,j-1));
    }
    return D[i][j];
  }

  public static void main(String[] args) {
    int n = 9;
    Character p[] = {'a','a','a','b','b','b','c','c','c'};
    int m = 7;
    Character t[] = {'d','a','d','f','b','c','f'};

    Lcs lcs = new Lcs();

    for (int i=0; i<=n; i++)
      for (int j=0; j<=m; j++)
        lcs.D[i][j] = -1;

    System.out.println("La sottosequenza comune massimale è lunga:");
    System.out.println(lcs.lcs(p, t, n, m));
  }
}
