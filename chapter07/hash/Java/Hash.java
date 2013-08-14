/*
 * Chapter 7
 * Paragraph 2
 *
 * Simple hash implementation
 */

import java.util.Set;
import java.util.TreeSet;
import java.util.Vector;


public class Hash<T> {
    private String[] A;
    private Vector<T> V;

    private Set<Integer> empty = new TreeSet<Integer>();
    private Set<Integer> deleted = new TreeSet<Integer>();
    private int m;

    public Hash(int capacita) {
        m = capacita;
        A = new String[m];

        V = new Vector<T>();
        for (int i=0; i<m; i++) {
            V.add(null);
        }

        for (int i=0; i<m; i++) {
            empty.add(i);
        }
    }

    public int scan(String k, boolean insert) {
        int c = m;
        int i = 0;
        int j = H(k);
        while (!empty.contains(j) && !A[j].equals(k) && i < m) {
            if (deleted.contains(j) && c == m) {
                c = j;
            }
            j = (j + H1(k)) % m;
            i++;
        }
        return j;
    }

    public T lookup(String k) {
        int i = scan(k, false);
        if (A[i].equals(k)) {
            return V.get(i);
        }
        return null;
    }

    public boolean insert(String k, T v) {
        int i = scan(k, true);
        if (empty.contains(i) || deleted.contains(i) || A[i].equals(k)) {
            A[i] = k;
            V.setElementAt(v, i);
            empty.remove(i);
            deleted.remove(i);
            return true;
        }
        else {
            return false;
        }
    }

    public void remove(String k) {
        int i = scan(k, false);
        if (!deleted.contains(i) && !empty.contains(i) && A[i].equals(k)) {
            deleted.add(i);
        }
    }

    private int H(String k) {
        double C = 0.6180339887498949;
        double b = k.charAt(0) * C;
        for (int j=1; j<k.length(); j++) {
            b = (((b * 256) + (k.charAt(j))) * C) % 1;
        }
        return (int) (((double) m) * b);
    }

    private int H1(String k) {
        int b = k.charAt(0);
        for (int j=1; j<k.length(); j++) {
            b = ((b * 256) + (k.charAt(j))) % m;
        }
        return b;
    }

    public static void main(String[] args) {
        Hash<Integer> myhash = new Hash<Integer>(15);
        myhash.insert("90's plaid", 3);
        myhash.insert("hipster ipsum", 1);
        myhash.remove("90's plaid");
        myhash.insert("Wes Anderson ", 2);
        myhash.insert("lomo", 4);
        myhash.insert("McSweeney's Tonx hashtag twee", 5);
        myhash.insert("vegan craft beer", 6);
        myhash.insert("90's plaid", 3);

        assert myhash.lookup("non esisto") == null;
        System.out.println(myhash.lookup("hipster ipsum"));
        System.out.println(myhash.lookup("Wes Anderson "));
        System.out.println(myhash.lookup("90's plaid"));
        System.out.println(myhash.lookup("lomo"));
        System.out.println(myhash.lookup("McSweeney's Tonx hashtag twee"));
        System.out.println(myhash.lookup("vegan craft beer"));
    }
}
