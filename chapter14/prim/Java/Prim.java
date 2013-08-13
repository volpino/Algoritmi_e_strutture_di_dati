/*
 * Chapter 14
 * Paragraph 3.2
 *
 * Prim minimum spanning tree algorithm
 */

import java.util.Set;
import java.util.Vector;


public class Prim {
    public static <T extends Comparable<? super T>> void compute(Graph<T> g, Node<T> r, int p[]) {
        HeapQueue<Node<T>> q = new HeapQueue<Node<T>>(g.numVertex());

        Vector<HeapItem<Node<T>>> pos = new Vector<HeapItem<Node<T>>>();
        for (int i=0; i<g.numVertex(); i++) {
            pos.add(i, null);
        }

        for (Node<T> it : g.v()) {
            if ((it) != r) {
                pos.setElementAt(q.insert(it, Integer.MAX_VALUE), g.id(it));
            }
        }

        pos.setElementAt(q.insert(r, 0), g.id(r));
        p[g.id(r)] = 0;

        while (q.size() != 0) {
            Node<T> u = q.min();
            q.deleteMin();

            pos.setElementAt(null, g.id(u));

            Set<Node<T>> adj = g.adj(u);
            for (Node<T> it : adj) {
                if (pos.get(g.id(it)) != null && g.w(u, it) < pos.get(g.id(it)).priority) {
                    q.decrease(pos.get(g.id(it)), g.w(u, it));
                    p[g.id(it)] = g.id(u);
                }
            }
        }
    }


    public static void main(String[] args) {
        MatrixGraph<Integer> g = new MatrixGraph<Integer>(10);

        Node<Integer> node1 = new Node<Integer>(1, 1);
        Node<Integer> node2 = new Node<Integer>(2, 2);
        Node<Integer> node3 = new Node<Integer>(3, 3);
        Node<Integer> node4 = new Node<Integer>(4, 4);
        Node<Integer> node5 = new Node<Integer>(5, 5);
        Node<Integer> node6 = new Node<Integer>(6, 6);
        Node<Integer> node7 = new Node<Integer>(7, 7);

        g.insertNode(node1);
        g.insertNode(node2);
        g.insertNode(node3);
        g.insertNode(node4);
        g.insertNode(node5);
        g.insertNode(node6);
        g.insertNode(node7);

        g.insertEdge(node1, node2, 9);
        g.insertEdge(node2, node1, 9);

        g.insertEdge(node1, node3, 6);
        g.insertEdge(node3, node1, 6);

        g.insertEdge(node2, node3, 11);
        g.insertEdge(node3, node2, 11);

        g.insertEdge(node2, node4, 5);
        g.insertEdge(node4, node2, 5);

        g.insertEdge(node2, node5, 20);
        g.insertEdge(node5, node2, 20);

        g.insertEdge(node3, node4, 2);
        g.insertEdge(node4, node3, 2);

        g.insertEdge(node3, node6, 18);
        g.insertEdge(node6, node3, 18);

        g.insertEdge(node4, node5, 13);
        g.insertEdge(node5, node4, 13);

        g.insertEdge(node4, node6, 28);
        g.insertEdge(node6, node4, 28);

        g.insertEdge(node4, node7, 15);
        g.insertEdge(node7, node4, 15);

        g.insertEdge(node5, node7, 3);
        g.insertEdge(node7, node5, 3);

        g.insertEdge(node6, node7, 25);
        g.insertEdge(node7, node6, 25);

        int[] p = new int[g.num_vertex];
        for (int i=0; i<g.num_vertex; i++) {
            p[i] = -1;
        }

        Prim.compute(g, node1, p);

        System.out.println("Node 1: " + g.id(node1));
        System.out.println("Node 2: " + g.id(node2));
        System.out.println("Node 3: " + g.id(node3));
        System.out.println("Node 4: " + g.id(node4));
        System.out.println("Node 5: " + g.id(node5));
        System.out.println("Node 6: " + g.id(node6));
        System.out.println("Node 7: " + g.id(node7));

        for (int i=1; i<g.num_vertex; i++) {
            if (p[i] != -1) {
                System.out.println((i+1) + " - " + (p[i]+1));
            }
        }
    }
}
