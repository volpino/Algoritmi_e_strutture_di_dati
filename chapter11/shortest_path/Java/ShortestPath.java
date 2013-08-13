/*
 * Chapter 11
 *
 * Shortest paths algorithms implementation
 */


public abstract class ShortestPath<T extends Comparable<? super T>> {
    public int[] d;
    public boolean[] b;
    public Graph<T> graph;

    void path(Graph<T> g, Node<T> r, int[] t) {
        graph = g;
        d = new int[g.numVertex()];
        b = new boolean[g.numVertex()];

        for (Node<T> node : g.v()) {
            t[g.id(node)] = -1;
            d[g.id(node)] = -1;
            b[g.id(node)] = false;
        }

        t[g.id(r)] = -1;
        d[g.id(r)] = 0;
        b[g.id(r)] = true;

        addToStructure(r, 0);

        while (!structureIsEmpty()) {
            Node<T> u = popFromStructure();
            b[g.id(u)] = false;

            for (Node<T> v : g.adj(u)) {
                if (d[g.id(v)] == -1 || d[g.id(u)] + g.w(u, v) < d[g.id(v)]) {
                    if (!b[g.id(v)]) {
                        addToStructure(v, d[g.id(u)] + g.w(u, v));
                    }
                    else {
                        alreadySeen(v, d[g.id(u)] + g.w(u ,v));
                    }
                    t[g.id(v)] = g.id(u);
                    d[g.id(v)] = d[g.id(u)] + g.w(u, v);
                }
            }
        }
    }

    abstract boolean structureIsEmpty();

    abstract Node<T> popFromStructure();

    abstract void addToStructure(Node<T> node, int weight);

    abstract void alreadySeen(Node<T> node, int weight);


    public static void main(String[] args) {
        ListsGraph<Integer> g = new ListsGraph<Integer>(10);
        Node<Integer> node1 = new Node<Integer>(1, 1);
        Node<Integer> node2 = new Node<Integer>(2, 2);
        Node<Integer> node3 = new Node<Integer>(3, 3);
        Node<Integer> node4 = new Node<Integer>(4, 4);
        Node<Integer> node5 = new Node<Integer>(5, 5);
        Node<Integer> node6 = new Node<Integer>(6, 6);

        g.insertNode(node1);
        g.insertNode(node2);
        g.insertNode(node3);
        g.insertNode(node4);
        g.insertNode(node5);
        g.insertNode(node6);

        g.insertEdge(node1, node2, 1);
        g.insertEdge(node1, node3, 2);

        g.insertEdge(node2, node5, 1);

        g.insertEdge(node3, node2, 3);
        g.insertEdge(node3, node4, 3);

        g.insertEdge(node4, node6, 2);

        g.insertEdge(node5, node4, 2);
        g.insertEdge(node5, node6, 5);

        int t[] = new int[10];

        System.out.println( "Dijkstra:");
        Dijkstra<Integer> dijkstra = new Dijkstra<Integer>();
        dijkstra.path(g, node1, t);

        System.out.print("Vector of parents: ");
        for (int i=0; i<6; i++) {
            System.out.print(t[i] + " ");
        }
        System.out.println("");

        System.out.println("Node 1: " + node1.cost);
        System.out.println("Node 2: " + node2.cost);
        System.out.println("Node 3: " + node3.cost);
        System.out.println("Node 4: " + node4.cost);
        System.out.println("Node 5: " + node5.cost);
        System.out.println("Node 6: " + node6.cost);


        System.out.println("");
        System.out.println("BellmanFord:");
        BellmanFord<Integer> bf = new BellmanFord<Integer>();
        bf.path(g, node1, t);

        System.out.print("Vector of parents: ");
        for (int i=0; i<6; i++) {
            System.out.print(t[i] + " ");
        }
        System.out.println("");

        System.out.println("Node 1: " + node1.cost);
        System.out.println("Node 2: " + node2.cost);
        System.out.println("Node 3: " + node3.cost);
        System.out.println("Node 4: " + node4.cost);
        System.out.println("Node 5: " + node5.cost);
        System.out.println("Node 6: " + node6.cost);


        System.out.println("");
        System.out.println("Pape D'Esopo:");
        PapeDEsopo<Integer> pe = new PapeDEsopo<Integer>();
        pe.path(g, node1, t);

        System.out.print("Vector of parents: ");
        for (int i=0; i<6; i++) {
            System.out.print(t[i] + " ");
        }
        System.out.println("");

        System.out.println("Node 1: " + node1.cost);
        System.out.println("Node 2: " + node2.cost);
        System.out.println("Node 3: " + node3.cost);
        System.out.println("Node 4: " + node4.cost);
        System.out.println("Node 5: " + node5.cost);
        System.out.println("Node 6: " + node6.cost);

    }
}
