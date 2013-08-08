/*
 * Chapter 12
 * Paragraph 2
 *
 * QuickSort algorithm implementation
 */


public class QuickSort {
    private static <T extends Comparable<? super T>> int perno(T A[], int primo, int ultimo) {
        T x = A[primo];
        int j = primo;

        for (int i=primo; i<=ultimo; i++) {
            if (A[i].compareTo(x) < 0) {
                j++;
                T tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
        A[primo] = A[j];
        A[j] = x;
        return j;
    }

    private static <T extends Comparable<? super T>> void quicksort_rec(T A[], int primo, int ultimo) {
        if (primo < ultimo) {
            int j = perno(A, primo, ultimo);
            quicksort_rec(A, primo, j-1);
            quicksort_rec(A, j+1, ultimo);
        }
    }

    public static <T extends Comparable<? super T>> void quicksort(T A[], int n) {
        quicksort_rec(A, 0, n-1);
    }

    public static void main(String[] args) {
        int DIM = 100;
        Integer a[] = new Integer[DIM];
        for (int i=0; i<DIM; i++)
            a[i] = DIM-i;

        QuickSort.quicksort(a, DIM);

        for (int i=0; i<DIM; i++)
            System.out.print(a[i] + " ");
        System.out.println("");
    }
}
