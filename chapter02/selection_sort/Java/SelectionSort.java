/*
 * Chapter 2
 * Paragraph 3
 *
 * Selection sort algorithm implementation
 */


public class SelectionSort {
  public static <T extends Comparable<? super T>> int min(T A[], int k) {
    int min = k;
    for (int h=k+1; h<A.length; h++)
      if (A[h].compareTo(A[min]) < 0)
        min = h;
    return min;
  }

  public static <T extends Comparable<? super T>> void sort(T A[]) {
    T t;
    for (int i=0; i<A.length; i++)
    {
      int j = min(A, i);
      t = A[i];
      A[i] = A[j];
      A[j] = t;
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
