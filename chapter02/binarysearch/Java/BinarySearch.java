/*
 * Chapter 2
 * Paragraph 1
 *
 * BinarySearch implementation
 */


public class BinarySearch {
    public static <T extends Comparable<? super T>> int search(T A[], T v) {
        return binsearch(A, v, 0, A.length);
    }

    public static <T extends Comparable<? super T>> int binsearch(T A[], T v, int i, int j) {
        if (i > j)
            return -1;

        int m = (i + j) / 2;  // integer division
        if (A[m].compareTo(v) == 0)
            return m;
        else if (A[m].compareTo(v) < 0)
            return binsearch(A, v, m+1, j);
        else
            return binsearch(A, v, i, m-1);
    }

    public static void main(String[] args) {
        Integer A[] = {-20, 2, 4, 9, 34, 42, 67, 234};
        System.out.println(search(A, 4));
        System.out.println(search(A, -20));
        System.out.println(search(A, 234));
    }
}
