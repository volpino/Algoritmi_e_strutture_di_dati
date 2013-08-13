/*
 * Chapter 2
 * Paragraph 3
 *
 * Selection sort algorithm implementation
 */


public class ShellSort {
  public static <T extends Comparable<? super T>> void sort(T A[]) {
    int n = A.length;
    int h = 1;
    while (h<=n)
    {
      h = 3*h + 1;
    }
    h = h/3;
    while (h>=1)
    {
      for (int i=h+1; i<=n; i++)
      {
        T temp = A[i-1];
        int j = i;
        while (j>h && A[j-h-1].compareTo(temp)>0)
        {
          A[j-1] = A[j-h-1];
          j = j - h;
        }
        A[j-1] = temp;
      }
      h = h/3;
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
