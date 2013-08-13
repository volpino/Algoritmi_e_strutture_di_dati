/*
 * Chapter 13
 * Paragraph 2
 */

import java.util.Collections;
import java.util.ArrayList;
import java.util.Set;
import java.util.TreeSet;

class IntVal implements Comparable<IntVal> {
    public int value;
    public int type;
    public int pos;

    public int compareTo(IntVal b) {
        return this.value - b.value;
    }
}


class Interval implements Comparable<Interval> {
    public int start;
    public int end;
    public int weight;

    public int compareTo(Interval b) {
        if (this.end == b.end) {
            return this.start - b.start;
        }
        else {
            return this.end - b.end;
        }

    }
}


public class MaxInterval {
    public static Set<Interval> maxinterval(ArrayList<Interval> intervals) {
        Collections.sort(intervals);

        ArrayList<IntVal> values = new ArrayList<IntVal>();
        int[] p = new int[intervals.size()];
        int[] D = new int[intervals.size() + 1];

        IntVal tmp;
        for (int i=0; i<intervals.size(); i++) {
            tmp = new IntVal();
            tmp.value = intervals.get(i).start;
            tmp.type = 0;
            tmp.pos = i;
            values.add(tmp);

            tmp = new IntVal();
            tmp.value = intervals.get(i).end;
            tmp.type = 1;
            tmp.pos = i;
            values.add(tmp);
        }

        Collections.sort(values);

        int i = -1;
        for (int j=0; j<values.size(); j++) {
            if (values.get(j).type == 0) {  // beginning of interval
                p[values.get(j).pos] = i;
            }
            else {  // end of interval
                i = values.get(j).pos;
            }
        }

        D[0] = 0;

        for (i=0; i<intervals.size(); i++) {
            D[i+1] = Math.max(D[i], intervals.get(i).weight + D[p[i] + 1]);
        }

        i = intervals.size() - 1;
        Set<Interval> s = new TreeSet<Interval>();

        while (i>=0) {
            if (D[i+1] > (intervals.get(i).weight + D[p[i] + 1])) {
                i--;
            }
            else {
                s.add(intervals.get(i));
                i = p[i];
            }
        }

        return s;
    }

    public static void main(String[] args) {
        ArrayList<Interval> intervals = new ArrayList<Interval>();
        Interval tmp;

        tmp = new Interval();
        tmp.start = 1;
        tmp.end = 2;
        tmp.weight = 1;
        intervals.add(tmp);

        tmp = new Interval();
        tmp.start = 1;
        tmp.end = 3;
        tmp.weight = 4;
        intervals.add(tmp);

        tmp = new Interval();
        tmp.start = 2;
        tmp.end = 5;
        tmp.weight = 5;
        intervals.add(tmp);

        tmp = new Interval();
        tmp.start = 3;
        tmp.end = 5;
        tmp.weight = 3;
        intervals.add(tmp);

        tmp = new Interval();
        tmp.start = 5;
        tmp.end = 5;
        tmp.weight = 6;
        intervals.add(tmp);

        Set<Interval> result = MaxInterval.maxinterval(intervals);

        System.out.println("Result: " + result.size());
        for (Interval it : result) {
            System.out.println(it.start + " - " + it.end);
        }
    }
}
