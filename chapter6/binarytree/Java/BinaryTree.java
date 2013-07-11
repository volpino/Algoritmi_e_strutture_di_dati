/*
 * Chapter 6
 * Paragraph 1
 *
 * Binary tree data structure implementation
 */

public class BinaryTree<T extends Comparable<? super T>> {
    private T _value;
    private T _key;
    private BinaryTree<T> parent;
    private BinaryTree<T> left;
    private BinaryTree<T> right;

    public BinaryTree(T k, T v) {
        _key = k;
        _value = v;
        parent = null;
        left = null;
        right = null;
    }

    public T key() {
        return _key;
    }

    public T value() {
        return _value;
    }

    public BinaryTree<T> lookupNode(T x) {
        BinaryTree<T> t = this;
        while (t != null && t.key() != x) {
            t = x.compareTo(t.key()) < 0 ? t.left : t.right;
        }
        return t;
    }

    public void link(BinaryTree<T> u, T x) {
        BinaryTree<T> v = this;
        if (u != null) {
            u.parent = v;
        }
        if (v != null) {
            if (x.compareTo(v.key()) < 0) {
                v.left = u;
            }
            else {
                v.right = u;
            }
        }
    }

    public void insertNode(T x, T v) {
        BinaryTree<T> s = null;
        BinaryTree<T> u = this;

        while (u != null && u.key() != x) {
            s = u;
            u = x.compareTo(u.key()) < 0 ? u.left : u.right;
        }
        if (u != null && u.key() == x) {
            u._value = v;
        }
        else {
            BinaryTree<T> n = new BinaryTree<T>(x, v);
            s.link(n, x);
        }
    }

    public void removeNode(T x) {
        BinaryTree<T> u = this.lookupNode(x);
        if (u != null) {
            if (u.left != null && u.right != null) {
                BinaryTree<T> s = u.right;
                while (s.left != null) {
                    s = s.left;
                }

                u._key = s.key();
                u._value = s.value();
                u = s;
            }

            BinaryTree<T> t;
            if (u.left != null && u.right == null) {
                t = u.left;
            }
            else {
                t = u.right;
            }
            if (u.parent == null) {
                // replace this with t
                this._value = t._value;
                this._key = t._key;
                this.parent = t.parent;
                this.left = t.left;
                this.right = t.right;
            }
            else {
                u.parent.link(t, x);
            }
        }
    }

    public BinaryTree<T> min() {
        BinaryTree<T> t = this;
        while (t.left != null) {
            t = t.left;
        }
        return t;
    }

    public BinaryTree<T> max() {
        BinaryTree<T> t = this;
        while (t.right != null) {
            t = t.right;
        }
        return t;
    }

    public BinaryTree<T> successorNode() {
        BinaryTree<T> t = this;
        if (t == null) {
            return t;
        }
        if (t.right != null) {
            return t.right.min();
        }
        BinaryTree<T> s = t.parent;
        while (s != null && t == s.right) {
            t = s;
            s = s.parent;
        }
        return s;
    }

    public BinaryTree<T> predecessorNode() {
        BinaryTree<T> t = this;
        if (t == null) {
            return t;
        }
        if (t.left != null) {
            return t.left.max();
        }
        BinaryTree<T> s = t.parent;
        while (s != null && t == s.left) {
            t = s;
            s = s.parent;
        }
        return s;
    }

    public static void main(String[] args) {
        BinaryTree<Integer> t = new BinaryTree<Integer>(1, 10);
        t.insertNode(2, 42);
        t.insertNode(99, 99);
        t.insertNode(2, 20);
        t.insertNode(0, 1);
        t.insertNode(5, 50);
        t.insertNode(3, 30);
        t.insertNode(4, 40);
        t.insertNode(0, 42);

        System.out.println("Il nodo minimo è " + t.min().key() + "=" + t.min().value());
        System.out.println("Il nodo massimo è " + t.max().key() + "=" + t.max().value());

        System.out.println("Rimuovo nodo 0");
        t.removeNode(0);

        System.out.println("Il nodo minimo è " + t.min().key() + "=" + t.min().value());
        System.out.println("");
        System.out.println("Ora stampo i nodi dell'albero in ordine: ");
        BinaryTree<Integer> s = t;
        while(s != null) {
            System.out.println("Nodo: " + s.key() + "=" + s.value());
            s = s.successorNode();
        }

        System.out.println("");
        System.out.println("Ora stampo i nodi dell'albero in ordine inverso: ");
        s = t.lookupNode(99);
        while(s != null) {
            System.out.println("Nodo: " + s.key() + "=" + s.value());
            s = s.predecessorNode();
        }
    }
}
