import java.util.Comparator;
import java.util.PriorityQueue;


public class Dijkstra<T extends Comparable<? super T>> extends ShortestPath<T> {
    PriorityQueue<Node<T>> s = new PriorityQueue<Node<T>>(100, new NodeCostComparator());

    public boolean structureIsEmpty() {
        return s.isEmpty();
    }

    public Node<T> popFromStructure() {
        return s.poll();
    }

    public void addToStructure(Node<T> node, int weight) {
        node.cost = weight;
        s.offer(node);
    }

    public void alreadySeen(Node<T> node, int weight) {
        s.remove(node);
        node.cost = weight;
        s.offer(node);
    }


    public class NodeCostComparator implements Comparator<Node<T>> {
        @Override
        public int compare(Node<T> a, Node<T> b) {
            return a.cost - b.cost;
        }
    }
}
