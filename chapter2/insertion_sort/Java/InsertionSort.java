/*
 * Chapter 2
 * Paragraph 3
 *
 * Insertion sort algorithm implementation
 */


public class InsertionSort {
    public static <T extends Comparable<? super T>> void sort(T A[]) {
        for (int i=1; i<A.length; i++) {
            T temp = A[i];
            int j = i;
            while (j>0 && A[j-1].compareTo(temp) > 0) {
                A[j] = A[j-1];
                j = j-1;
            }
            A[j] = temp;
        }
    }

    public static void main(String args[]) {
        Integer A[] = new Integer[100];
        for (int i=0; i<100; i++)
        {
            A[i] = 100 - i;
        }
        sort(A);
        for (int a : A)
            System.out.println(""+a);
    }
}
