import java.util.Deque;
import java.util.ArrayDeque;


public class PapeDEsopo<T extends Comparable<? super T>> extends ShortestPath<T> {
    Deque<Node<T>> s = new ArrayDeque<Node<T>>();

    public boolean structureIsEmpty() {
        return s.isEmpty();
    }

    public Node<T> popFromStructure() {
        return s.pollFirst();
    }

    public void addToStructure(Node<T> node, int weight) {
        if (this.d[this.graph.id(node)] == -1) {
            s.addLast(node);
        }
        else {
            s.addFirst(node);
        }
    }

    public void alreadySeen(Node<T> node, int weight) {
    }
}
