/*
 * Chapter 14
 * Paragraph 2
 *
 * Independent set of intervals, each one has weight 1
 */


import java.util.Collections;
import java.util.ArrayList;
import java.util.Set;
import java.util.TreeSet;


class Interval implements Comparable<Interval> {
  int start;
  int end;
  int pos;

  public int compareTo(Interval b) {
    return end - b.end;
  }
}

public class IndependentSet {
    public static void compute(int a[], int b[], int n, Set<Integer> output) {
        ArrayList<Interval> items = new ArrayList<Interval>();
        for (int i=0; i<n; i++) {
            Interval tmp = new Interval();
            tmp.start = a[i];
            tmp.end = b[i];
            tmp.pos = i;
            items.add(tmp);
        }

        Collections.sort(items);

        output.add(items.get(0).pos);
        int ultimo = 0;

        for (int i=1; i<n; i++) {
            if (items.get(i).start >= items.get(ultimo).end) {
                output.add(items.get(i).pos);
                ultimo = i;
            }
        }
    }

    public static void main(String args[]) {
        int n = 5;
        int a[] = {0, 3, 2, 9, 0};
        int b[] = {1, 4, 5, 12, 10};

        Set<Integer> output = new TreeSet<Integer>();

        IndependentSet.compute(a, b, n, output);

        System.out.print("Result: ");
        for (Integer it : output) {
            System.out.print(it + " ");
        }
        System.out.println("");
    }
}
