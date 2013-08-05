import java.util.TreeMap;
import java.util.ArrayList;


public class GraphTestFunctions {
    public static void test(Graph<Integer> g) {
        Node<Integer> a = new Node<Integer>(new Integer(1), new Integer(1));
        Node<Integer> b = new Node<Integer>(new Integer(2), new Integer(2));
        Node<Integer> c = new Node<Integer>(new Integer(3), new Integer(3));
        Node<Integer> d = new Node<Integer>(new Integer(4), new Integer(4));
        g.insertNode(a);
        g.insertNode(b);
        g.insertNode(c);
        g.deleteNode(c);
        g.insertNode(d);
        g.insertNode(c);

        g.insertEdge(a, b);
        g.deleteEdge(a, d);
        g.deleteEdge(a, b);

        g.insertEdge(a, b);
        g.insertEdge(a, c);
        g.insertEdge(a, d);
        g.insertEdge(b, c);
        g.insertEdge(c, a);
        g.insertEdge(d, c);
        g.insertEdge(d, b);

        System.out.println("Simple visit: ");
        GraphFunctions.visita(g, a);
        System.out.println("");

        System.out.println("BFS: ");
        GraphFunctions.bfs(g, a);
        System.out.println("");

        System.out.println("DFS: ");
        GraphFunctions.dfs(g, a);
        System.out.println("");

        System.out.println("Erdos: ");
        ArrayList<Node<Integer>> paths = new ArrayList<Node<Integer>>();
        int[] erdos_numbers = new int[g.numVertex()];
        GraphFunctions.erdos(g, c, erdos_numbers, paths);
        for (int i=0; i<g.numVertex(); i++) {
            System.out.print(erdos_numbers[i] + " ");
        }
        System.out.println("");


        System.out.println("stampaCammino");
        GraphFunctions.stampaCammino(g, c, d, paths);
        System.out.println("");

        System.out.println("Ciclico?: " + (GraphFunctions.is_ciclico(g) ? "Yes" : "No"));
        System.out.println("");

        System.out.print("Vicini del nodo 1 " + a + " :");
        for (Node<Integer> node : g.adj(a)) {
            System.out.print(" " + node.key);
        }
        System.out.println("");

        System.out.print("Vicini del nodo 2 " + b + " :");
        for (Node<Integer> node : g.adj(b)) {
            System.out.print(" " + node.key);
        }
        System.out.println("");

        System.out.print("Vicini del nodo 3 " + c + " :");
        for (Node<Integer> node : g.adj(c)) {
            System.out.print(" " + node.key);
        }
        System.out.println("");

        System.out.print("Vicini del nodo 4 " + d + " :");
        for (Node<Integer> node : g.adj(d)) {
            System.out.print(" " + node.key);
        }
        System.out.println("");

        System.out.println("SCC: ");
        TreeMap<Node<Integer>, Integer> scc_id = new TreeMap<Node<Integer>, Integer>();
        GraphFunctions.scc(g, scc_id);
        for (Node<Integer> node : scc_id.keySet()) {
            System.out.println("Node " + node.key + "=" + node.value + " => " + scc_id.get(node));
        }
        System.out.println("");

        System.out.println("TopSort: ");
        ArrayList<Node<Integer>> ordine = new ArrayList<Node<Integer>>();
        GraphFunctions.topSort(g, ordine);
        for (Node<Integer> node : ordine) {
            System.out.println("Node " + node.key + "=" + node.value);
        }
        System.out.println("");

        g.deleteEdge(a, c);
        g.deleteNode(d);

        System.out.print("Vicini del nodo 1:");
        for (Node<Integer> node : g.adj(a)) {
            System.out.print(" " + node.key);
        }
        System.out.println("");
    }
}
