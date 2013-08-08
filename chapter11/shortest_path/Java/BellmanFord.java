import java.util.Queue;
import java.util.concurrent.LinkedBlockingQueue;


public class BellmanFord<T extends Comparable<? super T>> extends ShortestPath<T> {
    Queue<Node<T>> s = new LinkedBlockingQueue<Node<T>>();

    public boolean structureIsEmpty() {
        return s.isEmpty();
    }

    public Node<T> popFromStructure() {
        return s.poll();
    }

    public void addToStructure(Node<T> node, int weight) {
        s.offer(node);
    }

    public void alreadySeen(Node<T> node, int weight) {
    }
}
