/*
 * Chapter 8
 * Paragraph 1
 *
 * Boolean vector set data structure
 */


public class BooleanSet {
    private boolean[] v;
    private int dim;
    private int tot;

    public BooleanSet(int n) {
        tot = n;
        dim = 0;
        v = new boolean[tot];
        for (int i=0; i<tot; i++) {
            v[i] = false;
        }
    };

    public int size() {
        return dim;
    };

    public boolean contains(int x) {
        if (x >= tot) {
            return false;
        }
        return v[x];
    };

    public void insert(int x) {
        if (x >= tot) {
            return;
        }
        if (!v[x]) {
            dim++;
        }
        v[x] = true;
    };

    public void remove(int x) {
        if (x >= tot) {
            return;
        }

        if (v[x]) {
            dim--;
        }
        v[x] = false;
    };

    public void unione(BooleanSet other) {
        int new_tot = Math.max(this.tot, other.tot);
        int new_dim = 0;
        boolean[] new_v = new boolean[new_tot];
        for (int i=0; i<new_tot; i++) {
            if (this.contains(i) || other.contains(i)) {
                new_v[i] = true;
                new_dim++;
            }
            else {
                new_v[i] = false;
            }
        }
        this.v = new_v;
        this.tot = new_tot;
        this.dim = new_dim;
    }

    public void intersection(BooleanSet other) {
        int new_dim = 0;
        boolean[] new_v = new boolean[this.tot];
        for (int i=0; i<this.tot; i++) {
            if (this.contains(i) && other.contains(i)) {
                new_v[i] = true;
                new_dim++;
            }
            else {
                new_v[i] = false;
            }
        }
        this.v = new_v;
        this.dim = new_dim;
    }

    public void difference(BooleanSet other) {
        int new_dim = 0;
        boolean[] new_v = new boolean[this.tot];
        for (int i=0; i<this.tot; i++) {
            if (this.contains(i) && !other.contains(i)) {
                new_v[i] = true;
                new_dim++;
            }
            else {
                new_v[i] = false;
            }
        }
        this.v = new_v;
        this.dim = new_dim;
    }

    public static void main(String args[]) {
        BooleanSet s = new BooleanSet(10);
        s.insert(3);
        s.insert(6);
        System.out.println("Set s size: " + s.size());

        BooleanSet t = new BooleanSet(100);
        t.insert(42);
        t.insert(21);
        t.insert(91);
        System.out.println("Set t size: " + t.size());

        s.unione(t);

        System.out.println("Set s size: " + s.size());
        System.out.println("Set s contains 42 and 6? " + (s.contains(42) && s.contains(6) ? "Yes" : "No"));
    }
}
