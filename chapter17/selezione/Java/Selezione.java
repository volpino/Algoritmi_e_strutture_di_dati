/*
 * Chapter 17
 * Paragraph 1
 *
 * Selection algorithm
 */

class Selezione {
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
    };

    public static <T extends Comparable<? super T>> T compute(T A[], int primo, int ultimo, int k) {
        if (primo == ultimo) {
            return A[primo];
        }

        // to enforce randomness
        int rnd = (int) (Math.random() * (ultimo - primo + 1)) + primo ;
        T tmp = A[rnd];
        A[rnd] = A[primo];
        A[primo] = tmp;

        int j = perno(A, primo, ultimo);
        int q = j - primo + 1;
        if (k == q) {
            return A[j];
        }
        else if (k <= q) {
            return compute(A, primo, j-1, k);
        }
        else {
            return compute(A, j+1, ultimo, k-q);
        }
    }

    public static void main(String[] args) {
        Integer array[] = {3, 4, 1, 2, 9, 7, 6, 5, 8};
        System.out.println("Min: " + Selezione.compute(array, 0, 8, 1));
        System.out.println("Max: " + Selezione.compute(array, 0, 8, 9));
        System.out.println("Mediana: " + Selezione.compute(array, 0, 8, 5));
    }
}
