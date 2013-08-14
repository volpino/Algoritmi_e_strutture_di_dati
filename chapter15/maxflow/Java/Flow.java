/*
 * Chapter 15
 * Paragraph 2
 */

public class Flow {
  //search augmenting path with depth first search
  public static <T extends Comparable<? super T>> int dfs(Graph<T> G,
                            int r[][], //residual capacity
                            int i,   //current node
                            int p,   //sink
                            boolean visited[],
                            int min,
                            int g[][]) {//output augmenting flow
    //if sink has been reached, terminate
    if (i==p)
    {
      return min;
    }

    visited[i] = true;
    for (int j=0; j < G.numVertex(); j++)
    {
      if (r[i][j] > 0 && !visited[j])
      {
        // For each adjacent node j that has not been visited...

        // Recursively perform the DFS, using the capacity of edge [i,j]
        //if smaller than the min found so far.
        int v = dfs(G, r, j, p, visited, Math.min(min, r[i][j]), g);

        // If v>0, we have found the sink, and v is the maximu value of the flow
        //along the path connecting the source and sink.
        if (v > 0)
        {
          r[i][j] = r[i][j]-v;
          g[i][j] = g[i][j]+v;
          r[j][i] = r[j][i]+v;
          g[j][i] = g[j][i]-v;
          return v;
        }
      }
    }
    // The sink has not been found.
    return 0;
  }

  //returns true if an augmenting path is found
  public static <T extends Comparable<? super T>> boolean augmenting_flow(Graph<T> G,
                                            int r[][], //residual capacity
                                            int s,   //source
                                            int p,   //sink
                                            int g[][] //output augmenting flow
    ) {
    boolean visited[] = new boolean[G.numVertex()];
    for (int i=0; i<G.numVertex(); i++)
      visited[i] = false;
    //initial flow is zero
    for (Node<T> i : G.v())
    {
      for (Node<T> j : G.v())
      {
        int u = G.id(i);
        int v = G.id(j);
        g[u][v] = 0;
      }
    }
    int min = dfs(G, r, s, p, visited, Integer.MAX_VALUE, g);

    return (min > 0);
  }

  public static <T extends Comparable<? super T>> void maxFlow(Graph<T> G,
                                 int s, //source
                                 int p, //sink
                                 int f[][]) { //flow matrix output
    //initialize matrix for augmenting path
    int g[][] = new int[G.numVertex()][G.numVertex()];

    //initialize matrix for remaining flow net
    int r[][] = new int[G.numVertex()][G.numVertex()];

    //initial flow is zero
    for (Node<T> i : G.v())
    {
      for (Node<T> j : G.v())
      {
        int u = G.id(i);
        int v = G.id(j);
        f[u][v] = 0;
      }
    }

    boolean stop = false;
    while (!stop)
    {
      //compute remaining flow net in r
      for (Node<T> i : G.v())
      {
        for (Node<T> j : G.v())
        {
          int u = G.id(i);
          int v = G.id(j);
          r[u][v] = G.w(i,j) - f[u][v];
        }
      }

      //compute augmenting flow over r
      stop = !augmenting_flow(G, r, s, p, g);

      //update new flow
      for (Node<T> i : G.v())
      {
        for (Node<T> j : G.v())
        {
          int u = G.id(i);
          int v = G.id(j);
          f[u][v] += g[u][v];
        }
      }
    }
  }

  public static void main(String[] args) {
    // Create a graph with 6 nodes
    int n=6;
    MatrixGraph<Integer> G = new MatrixGraph<Integer>(n);
    Node<Integer> n1 = new Node<Integer>(1, 1);
    Node<Integer> n2 = new Node<Integer>(2, 2);
    Node<Integer> n3 = new Node<Integer>(3, 3);
    Node<Integer> n4 = new Node<Integer>(4, 4);
    Node<Integer> n5 = new Node<Integer>(5, 5);
    Node<Integer> n6 = new Node<Integer>(6, 6);
    G.insertNode(n1);
    G.insertNode(n2);
    G.insertNode(n3);
    G.insertNode(n4);
    G.insertNode(n5);
    G.insertNode(n6);

    //Add edges
    G.insertEdge(n1,n2,2);
    G.insertEdge(n1,n3,25);
    G.insertEdge(n2,n4,5);
    G.insertEdge(n2,n3,8);
    G.insertEdge(n2,n5,11);
    G.insertEdge(n3,n4,7);
    G.insertEdge(n3,n5,6);
    G.insertEdge(n4,n6,25);
    G.insertEdge(n5,n6,35);

    // Create an empty flow
    int f[][] = new int[G.num_vertex][G.num_vertex];

    maxFlow(G,G.id(n1),G.id(n6),f);

    for (int i=0; i<G.num_vertex; i++)
    {
      for (int j=0; j<G.num_vertex; j++)
        System.out.print(f[i][j]+" ");
      System.out.println();
    }
  }
}