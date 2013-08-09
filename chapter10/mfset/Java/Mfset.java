/*
 * Chapter 19
 * Paragraph 2
 *
 */

import java.util.Scanner;

public class Mfset {
  private int p[];
  private int rango[];

  public Mfset(int n) {
    this.p = new int[n+1];
    this.rango = new int[n+1];
    for (int i=0; i<=n; i++)
    {
      this.p[i] = i;
      this.rango[i] = 0;
    }
  }

  public int find(int x) {
    if (p[x] != x)
      p[x] = this.find(p[x]);
    return p[x];
  }

  public void merge(int x, int y) {
    int r_x = this.find(x);
    int r_y = this.find(y);
    if (r_x != r_y)
    {
      if (rango[r_x] > rango[r_y])
        p[r_y] = r_x;
      else if (rango[r_y] > rango[r_x])
        p[r_x] = r_y;
      else
      {
        p[r_x] = r_y;
        rango[r_y] = rango[r_y] + 1;
      }
    }
  }

  public static void main(String[] args) {
    Mfset mf = new Mfset(100);
    Scanner in = new Scanner(System.in);
    while (true)
    {
      int a,b;
      System.out.println("Merge?");
      a = in.nextInt();
      b = in.nextInt();
      mf.merge(a,b);
      System.out.println("Find?");
      a = in.nextInt();
      System.out.println("Rapr "+mf.find(a));
    }
  }
}