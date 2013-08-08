import java.util.ArrayList;
import java.util.TreeSet;
import java.util.Set;
import java.util.TreeMap;


public class ListsGraph<T extends Comparable<? super T>> implements Graph<T> {
    private ArrayList<ArrayList<Node<T>>> adj_list = new ArrayList<ArrayList<Node<T>>>();
    private TreeSet<Node<T>> vertices = new TreeSet<Node<T>>();
    private TreeSet<Integer> available_ids = new TreeSet<Integer>();
    private TreeMap<Node<T>, Integer> node_ids = new TreeMap<Node<T>, Integer>();

    public int num_vertex;


    public ListsGraph(int num_vertex) {
        this.num_vertex = num_vertex;
        adj_list.ensureCapacity(num_vertex);

        for (int i=0; i<num_vertex; i++) {
            available_ids.add(i);
            adj_list.add(new ArrayList<Node<T>>());
        }
    }

    public void insertNode(Node<T> node) {
        if (available_ids.isEmpty() || vertices.contains(node)) {
            return;
        }
        node_ids.put(node, available_ids.first());
        available_ids.remove(id(node));
        vertices.add(node);
    }

    public void insertEdge(Node<T> a, Node<T> b) {
        if (!vertices.contains(a) || !vertices.contains(b)) {
            return;
        }
        adj_list.get(id(a)).add(b);
    }

    public void deleteNode(Node<T> node) {
        if (id(node) >= this.num_vertex || available_ids.contains(id(node))) {
            return;
        }
        vertices.remove(node);
        adj_list.get(id(node)).clear();
        available_ids.add(id(node));

        // removing incoming edges
        for (int i=0; i<adj_list.size(); i++) {
            while (adj_list.get(i).remove(node));
        }
    }

    public void deleteEdge(Node<T> a, Node<T> b) {
        if (!vertices.contains(a) || !vertices.contains(b)) {
            return;
        }
        adj_list.get(id(a)).remove(b);
    }

    public Set<Node<T> > adj(Node<T> node) {
        if (!vertices.contains(node)) {
            return null;
        }
        Set<Node<T> > adjacent_set = new TreeSet<Node<T> >();
        for (int i=0; i<adj_list.get(id(node)).size(); i++) {
            adjacent_set.add(adj_list.get(id(node)).get(i));
        }

        return adjacent_set;
    }

    public Set<Node<T> > v() {
        return vertices;
    }

    public int id(Node<T> node) {
        return node_ids.get(node);
    }

    public int numVertex() {
        return num_vertex;
    }

    public int w(Node<T> a, Node<T> b) {
        // not efficient, just for teaching purposes. As the book does not cover
        // the implementation of a graph with weighted edges, here it is a
        // simplification of it, needed for implementing other algorithms such as
        // Dijkstra's algorithm for shortest path.
        int count = 0;
        for (int i=0; i<adj_list.get(id(a)).size(); i++) {
            if (adj_list.get(id(a)).get(i) == b) {
                count++;
            }
        }
        return count;
    }

    public static void main(String args[]) {
        GraphTestFunctions.test(new ListsGraph<Integer>(10));
    }
}
