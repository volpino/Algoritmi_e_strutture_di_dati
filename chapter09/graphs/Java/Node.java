public class Node<T extends Comparable<? super T>> implements Comparable<Node<T>> {
    public T key;
    public T value;
    public int cost;

    public Node(T k, T v) {
        key = k;
        value = v;
    }

    public int compareTo(Node<T> other) {
        return key.compareTo(other.key);
    }
}
