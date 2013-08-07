/*
 * Chapter 10
 * Paragraph 1.4
 *
 * Heap priority queue data structure
 */


public class HeapSort<T extends Comparable<? super T>> {
    private T[] array;
    private int n;

    public HeapSort(T[] array, int n) {
        this.array = array;
        this.n = n;
    }

    public void heapBuild() {
        for (int i=n/2; i>=0; i--) {
            maxHeapRestore(i);
        }
    }

    public void maxHeapRestore(int i) {
        int max = i;
        if (left(i) < n && array[left(i)].compareTo(array[max]) > 0) {
            max = left(i);
        }

        if (right(i) < n && array[right(i)].compareTo(array[max]) > 0) {
            max = right(i);
        }

        if (i != max) {
            swap(i, max);
            maxHeapRestore(max);
        }
    }

    public void heapSort() {
        heapBuild();
        for (int i=n-1; i>=0; i--) {
            swap(0, i);
            n--;
            maxHeapRestore(0);
        }
    }

    private void swap(int i, int j) {
        T tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
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

    public static void main(String args[]) {
        Integer array[] = {4, 8, 23, 1, 5, 9, 12, 0};
        HeapSort<Integer> h = new HeapSort<Integer>(array, 8);
        h.heapSort();

        for (int i=0; i<8; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println("");
    }
}
