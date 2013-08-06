/*
 * Chapter 10
 * Paragraph 3
 *
 * Heap priority queue data structure
 */


import java.util.ArrayList;


public class HeapQueue<T extends Comparable<? super T>> {
    private int used_slots;
    private int total;
    private ArrayList<HeapItem<T>> array;

    public HeapQueue(int n) {
        total = n;
        used_slots = 0;
        array = new ArrayList<HeapItem<T>>();
    }

    public int size() { return used_slots; };

    public T min() {
        if (used_slots == 0) {
            return null;
        }

        return array.get(0).value;
    }

    public boolean insert(T value, int priority) {
        if (used_slots >= total) {
            return false;
        }

        array.add(new HeapItem<T>(value, priority, used_slots));

        int i = used_slots;
        while (i > 0 && array.get(i).priority < array.get(parent(i)).priority) {
            swap(i, parent(i));
            i = parent(i);
        }

        used_slots++;

        return true;
    }

    public void minHeapRestore(int i) {
        int min = i;
        if (left(i) < used_slots && array.get(left(i)).priority < array.get(min).priority) {
            min = left(i);
        }

        if (right(i) < used_slots && array.get(right(i)).priority < array.get(min).priority) {
            min = right(i);
        }

        if (i != min) {
            swap(i, min);
            minHeapRestore(min);
        }
    };

    public void deleteMin() {
        if (used_slots == 0) {
            return;
        }

        used_slots--;
        swap(0, used_slots);

        minHeapRestore(0);
    }

    private void swap(int i, int j) {
        HeapItem<T> first = array.get(i);
        HeapItem<T> second = array.get(j);
        array.remove(i);
        array.add(i, second);
        array.remove(j);
        array.add(j, first);
        array.get(i).pos = i;
        array.get(j).pos = j;
    }

    private int parent(int i) {
        return i / 2;  // integer division
    }

    private int left(int i) {
        return 2 * i;
    }

    private int right(int i) {
        return (2 * i) + 1;
    }

    class HeapItem<T extends Comparable<? super T>> {
        public T value;
        public int priority;
        public int pos;

        public HeapItem(T value, int priority, int pos) {
            this.value = value;
            this.priority = priority;
            this.pos = pos;
        }
    }

    public static void main(String args[]) {
        HeapQueue<Integer> h = new HeapQueue<Integer>(10);

        h.insert(4, 4);
        h.insert(8, 8);
        h.insert(23, 23);
        h.insert(1, 1);
        h.insert(5, 5);
        h.insert(9, 9);
        h.insert(12, 12);
        h.insert(0, 0);
        System.out.println("Size: " + h.size());

        for (int i=h.size(); i>0; i--) {
            System.out.print(h.min() + " ");
            h.deleteMin();
        }
        System.out.println("");
    }
}
