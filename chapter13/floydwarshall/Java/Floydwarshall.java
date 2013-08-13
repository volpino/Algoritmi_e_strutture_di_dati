/*
 *
 * Chapter 13
 * Paragraph 5
 *
 */

public class Floydwarshall {
  public final int MAX_N = 100;
  public int d[][] = new int[MAX_N][MAX_N];
  public int p[][] = new int[MAX_N][MAX_N];

  public <T extends Comparable<? super T>> void floydWarshall(Graph<T> G) {
    for (Node<T> i : G.v()) {
      int u = G.id(i);
      for (Node<T> j : G.v()) {
        int v = G.id(j);
        if (u==v)
          d[u][v] = 0;
        else
          d[u][v] = Integer.MAX_VALUE;
        p[u][v] = 0;
      }
    }
    for (Node<T> i : G.v())
    {
      int u = G.id(i);
      for (Node<T> j : G.adj(i))
      {
        int v = G.id(j);
        d[u][v] = G.w(i,j);
        p[u][v] = u+1;
      }
    }
    for (int k=0; k<G.numVertex(); k++)
    {
      for (Node<T> i : G.v())
      {
        int u = G.id(i);
        for (Node<T> j : G.v())
        {
          int v = G.id(j);
          if (d[u][k]!=Integer.MAX_VALUE &&
              d[k][v]!=Integer.MAX_VALUE &&
              d[u][k] + d[k][v] < d[u][v])
          {
            d[u][v] = d[u][k] + d[k][v];
            p[u][v] = p[k][v];
          }
        }
      }
    }
  }

  public static void main(String args[]) {
    int n = 4;
    MatrixGraph<Integer> g = new MatrixGraph<Integer>(n);
    Node<Integer> n1 = new Node<Integer>(1, 1);
    Node<Integer> n2 = new Node<Integer>(2, 2);
    Node<Integer> n3 = new Node<Integer>(3, 3);
    Node<Integer> n4 = new Node<Integer>(4, 4);
    Node<Integer> n5 = new Node<Integer>(5, 5);

    g.insertNode(n1);
    g.insertNode(n2);
    g.insertNode(n3);
    g.insertNode(n4);
    g.insertNode(n5);

    g.insertEdge(n1, n2, 5);
    g.insertEdge(n1, n3, 2);
    g.insertEdge(n2, n3, 3);
    g.insertEdge(n2, n4, 4);
    g.insertEdge(n3, n4, 5);
    g.insertEdge(n4, n2, -3);

    Floydwarshall fw = new Floydwarshall();
    fw.floydWarshall(g);

    System.out.println("Distances between nodes");
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++)
      {
        System.out.print(fw.d[i][j]+" ");
      }
      System.out.print("\n");
    }

    System.out.println("Predecessors");
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++)
      {
        System.out.print(fw.p[i][j]+" ");
      }
      System.out.print("\n");
    }
  }
}
