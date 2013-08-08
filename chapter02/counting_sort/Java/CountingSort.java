/*
 * Chapter 2
 * Paragraph 4
 *
 * Counting sort algorithm implementation
 */


public class CountingSort {
    public static void sort(int A[], int k) {
        int i, j;

        k += 1;
        int B[] = new int[k];

        for (i=0; i<k; i++)
            B[i] = 0;

        for (i=0; i<A.length; i++)
            B[A[i]] += 1;

        j = 0;
        for (i=0; i<k; i++) {
            while (B[i] > 0) {
                A[j] = i;
                j += 1;
                B[i] -= 1;
            }
        }
    }

    public static void main(String args[]) {
        int A[] = new int[100];
        for (int i=0; i<100; i++) {
            A[i] = 100 - i;
        }
        sort(A, 100);
        for (int a : A)
            System.out.println(""+a);
    }
}
