import java.util.Set;
import java.util.TreeSet;
import java.util.TreeMap;
import java.util.ArrayList;


public class MatrixGraph<T extends Comparable<? super T>> implements Graph<T> {
    private TreeSet<Node<T>> vertices = new TreeSet<Node<T>>();
    private TreeSet<Integer> available_ids = new TreeSet<Integer>();
    private TreeMap<Node<T>, Integer> node_ids = new TreeMap<Node<T>, Integer>();
    private int[][] matrix;
    private ArrayList<Node<T>> vertices_ids = new ArrayList<Node<T>>();

    public int num_vertex;


    public MatrixGraph(int num_vertex) {
        this.num_vertex = num_vertex;
        matrix = new int[numVertex()][numVertex()];
        for (int i=0; i<num_vertex; i++) {
            matrix[i] = new int[num_vertex];
        }

        for (int i=0; i<num_vertex; i++) {
            for (int j=0; j<num_vertex; j++) {
                matrix[i][j] = 0;
            }
            available_ids.add(i);
        }
    }

    public void insertNode(Node<T> node) {
        if (available_ids.isEmpty()) {
            return;
        }
        node_ids.put(node, available_ids.first());
        available_ids.remove(id(node));
        vertices.add(node);
        vertices_ids.add(id(node), node);
    }

    public void insertEdge(Node<T> a, Node<T> b) {
        if (!vertices.contains(a) || !vertices.contains(b)) {
            return;
        }
        matrix[id(a)][id(b)]++;
    }

    public void insertEdge(Node<T> a, Node<T> b, int w) {
        if (!vertices.contains(a) || !vertices.contains(b)) {
            return;
        }
        matrix[id(a)][id(b)] = w;
    }

    public void deleteNode(Node<T> node) {
        if (id(node) >= this.num_vertex || available_ids.contains(id(node))) {
            return;
        }
        vertices.remove(node);
        for (int i=0; i<this.num_vertex; i++) {
            matrix[id(node)][i] = 0;
            matrix[i][id(node)] = 0;
        }
        available_ids.add(id(node));
    }

    public void deleteEdge(Node<T> a, Node<T> b) {
        if (!vertices.contains(a) || !vertices.contains(b)) {
            return;
        }
        if (matrix[id(a)][id(b)] > 0) {
            matrix[id(a)][id(b)]--;
        }
    }

    public Set<Node<T>> adj(Node<T> node) {
        if (!vertices.contains(node)) {
            return null;
        }
        Set<Node<T>> adjacent_set = new TreeSet<Node<T>>();
        for (int i=0; i<this.num_vertex; i++) {
            if (matrix[id(node)][i] != 0) {
                adjacent_set.add(vertices_ids.get(i));
            }
        }

        return adjacent_set;
    }

    public Set<Node<T>> v() {
        return vertices;
    }

    public int id(Node<T> node) {
        return node_ids.get(node);
    }

    public int numVertex() {
        return num_vertex;
    }

    public int w(Node<T> a, Node<T> b) {
        return matrix[id(a)][id(b)];
    }

    public static void main(String args[]) {
        GraphTestFunctions.test(new MatrixGraph<Integer>(10));
    }
}
