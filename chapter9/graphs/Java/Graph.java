import java.util.Set;


public interface Graph<T extends Comparable<? super T>> {
    void insertNode(Node<T> node);
    void insertEdge(Node<T> a, Node<T> b);
    void deleteNode(Node<T> node);
    void deleteEdge(Node<T> a, Node<T> b);
    Set<Node<T> > adj(Node<T> node);
    Set<Node<T> > v();
    int id(Node<T> node);
    int numVertex();
    int w(Node<T> a, Node<T> b);
}
