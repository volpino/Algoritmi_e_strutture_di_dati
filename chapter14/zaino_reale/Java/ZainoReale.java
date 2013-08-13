/*
 * Chapter 14
 * Paragraph 1
 *
 * Rucksack problem with real numbers
 */

import java.util.ArrayList;
import java.util.Collections;


class Item implements Comparable<Item> {
    int profit;
    int volume;
    int pos;

    public int compareTo(Item b) {
        if ((((double) profit) / volume) < (((double) b.profit) / b.volume)) {
            return 1;
        }
        if ((((double) profit) / volume) > (((double) b.profit) / b.volume)) {
            return -1;
        }
        return 0;
    }
}


public class ZainoReale {
    public static void zaino(int p[], int v[], int c, int n, double x[]) {
        ArrayList<Item> items = new ArrayList<Item>();
        for (int i=0; i<n; i++) {
            Item obj = new Item();
            obj.profit = p[i];
            obj.volume = v[i];
            obj.pos = i;
            items.add(obj);
        }

        Collections.sort(items);

        for (int i=0; i<n; i++) x[i] = 0;

        int i = 0;
        while (i<n && c>0) {
            if (items.get(i).volume >= c) {
                x[items.get(i).pos] = ((double) c) / items.get(i).volume;
                c = 0;
            }
            else {
                x[items.get(i).pos] = 1;
                c = c - items.get(i).volume;
            }
            i++;
        }
    }

    public static void main(String[] args) {
        int p[] = {10, 99, 3, 21, 12, 64, 42, 64, 90, 10};
        int v[] = {30, 60, 2, 50, 15, 5, 10, 20, 25, 10};
        int n = 10;
        double x[] = new double[10];
        int c = 50;

        zaino(p, v, c, n, x);

        System.out.print("Result: ");
        for (int i=0; i<n; i++) {
            System.out.print(x[i] + " ");
        }
        System.out.println("");
    }
}
