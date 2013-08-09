/*
 * Chapter 6
 * Paragraph 2
 *
 */

import java.util.Random;
import java.util.ArrayList;
import java.util.Collections;

public class RBTree<Key extends Comparable<? super Key>, T> {
  public enum Color {
    RED, BLACK
  }

  private Key key;
  private T value;
  private Color color;
  private RBTree left;
  private RBTree right;
  private RBTree parent;

  public RBTree(Key k, T v) {
    key = k;
    value = v;
    color = Color.BLACK;
    left = null;
    right = null;
    parent = null;
  }

  public RBTree<Key,T> lookupNode(Key x)
  {
    RBTree<Key,T> t = this;
    while (t != null && t.key != x) {
      t = (x.compareTo(t.key) < 0) ? t.left : t.right;
    }
    return t;
  }

  public RBTree<Key,T> insertNode(Key x, T v)
  {
    RBTree<Key, T> s = null;
    RBTree<Key, T> u = this;

    while (u != null && u.key != x)
    {
      s = u;
      u = (x.compareTo(u.key) < 0) ? u.left : u.right;
    }
    if (u != null && u.key == x)
    {
      u.value = v;
    }
    else
    {
      RBTree<Key,T> n = new RBTree<Key, T>(x, v);
      n.color = Color.RED;
      s.link(n, x);
      n.balanceInsert();
    }
    //return the new root
    u = this;
    while(u.parent != null)
      u = u.parent;
    return u;
  }

  public RBTree<Key,T> removeNode(Key x)
  {
    RBTree<Key,T> Tr = this;
    RBTree<Key,T> u = Tr.lookupNode(x);
    if (u != null)
    {
      if (u.left != null && u.right != null)
      {
        RBTree<Key,T> s = u.right;
        while (s.left != null)
        {
          s = s.left;
        }

        u.key = s.key;
        u.value = s.value;

        x = s.key;
        u = s;
      }

      RBTree<Key,T> t;
      if (u.left != null && u.right == null)
      {
        t = u.left;
      }
      else
      {
        t = u.right;
      }
      if (u.parent == null)
      {
        //Tr is the new root
        Tr = t;
        Tr.parent = null;
      }
      else
      {
        u.parent.link(t, x);
      }
      if (u.color == Color.BLACK)
        this.balanceDelete(t,u.parent);
    }
    //return the new root
    while(Tr.parent != null)
      Tr = Tr.parent;
    return Tr;
  }

  public void checkTree()
  {
    assert(this.color == Color.BLACK);
    this.checkChildren();
    blackHeight();
  }

  public void checkChildren()
  {
    if (this.color == Color.RED)
    {
      if (this.left != null)
        assert(this.left.color == Color.BLACK);
      if (this.right != null)
        assert(this.right.color == Color.BLACK);
    }
    if (this.left != null)
      this.left.checkChildren();
    if (this.right != null)
      this.right.checkChildren();
  }

  public int blackHeight()
  {
    int s = (this.left != null) ? this.left.blackHeight() : 1;
    int r = (this.right != null) ? this.right.blackHeight() : 1;
    assert(s==r);
    if (this.color == Color.BLACK)
      s++;
    return s;
  }

  private void balanceInsert()
  {
    RBTree t = this;
    while (t != null)
    {
      RBTree p = t.parent;
      RBTree n = (p!=null) ? p.parent : null;
      RBTree z = (n==null) ? null : ((n.left == p) ? n.right : n.left);
      if (p == null)  //case 1
      {
        t.color = Color.BLACK;
        t = null;
      }
      else if (p.color == Color.BLACK) //case 2
      {
        t = null;
      }
      else if (z != null && z.color == Color.RED) //case 3
      {
        p.color = z.color = Color.BLACK;
        n.color = Color.RED;
        t = n;
      }
      else
      {
        if (t == p.right && p == n.left) //case 4.a
        {
          p.rotateLeft();
          t = p;
        }
        else if (t == p.left && p == n.right) //case 4.b
        {
          p.rotateRight();
          t = p;
        }
        else
        {
          if (t==p.left && p==n.left) //case 5.a
            n.rotateRight();
          else if (t==p.right && p==n.right)
            n.rotateLeft();
          p.color = Color.BLACK;
          n.color = Color.RED;
          t = null;
        }
      }
    }
  }

  private void balanceDelete(RBTree<Key,T> t, RBTree<Key,T> p)
  {
    RBTree<Key,T> Tr = this;
    while ((t == null) || (t!=Tr && t.color == Color.BLACK))
    {
      if (t != null)
        p = t.parent;
      if (t == p.left)
      {
        RBTree<Key,T> f = p.right;
        RBTree<Key,T> ns = f.left;
        RBTree<Key,T> nd = f.right;
        if (f.color == Color.RED) //case 1
        {
          p.color = Color.RED;
          f.color = Color.BLACK;
          p.rotateLeft();
        }
        else
        {
          Color ns_color = (ns != null) ? ns.color : Color.BLACK;
          Color nd_color = (nd != null) ? nd.color : Color.BLACK;
          if (ns_color == nd_color && nd_color == Color.BLACK) //case 2
          {
            f.color = Color.RED;
            t = p;
          }
          else if (ns_color == Color.RED && nd_color == Color.BLACK) //case 3
          {
            ns.color = Color.BLACK;
            f.color = Color.RED;
            f.rotateRight();
          }
          else if (nd_color == Color.RED) // case4
          {
            f.color = p.color;
            p.color = Color.BLACK;
            nd.color = Color.BLACK;
            p.rotateLeft();
            //update root
            while (Tr.parent != null)
              Tr = Tr.parent;
            t = Tr;
          }
        }
      }
      else
      {
        RBTree<Key,T> f = p.left;
        RBTree<Key,T> ns = f.left;
        RBTree<Key,T> nd = f.right;
        if (f.color == Color.RED) //case 1
        {
          p.color = Color.RED;
          f.color = Color.BLACK;
          p.rotateRight();
        }
        else
        {
          Color ns_color = (ns != null) ? ns.color : Color.BLACK;
          Color nd_color = (nd != null) ? nd.color : Color.BLACK;
          if (ns_color == nd_color && nd_color == Color.BLACK) //case 2
          {
            f.color = Color.RED;
            t = p;
          }
          else if (nd_color == Color.RED && ns_color == Color.BLACK) //case 3
          {
            nd.color = Color.BLACK;
            f.color = Color.RED;
            f.rotateLeft();
          }
          else if (ns_color == Color.RED) // case4
          {
            f.color = p.color;
            p.color = Color.BLACK;
            ns.color = Color.BLACK;
            p.rotateRight();
            //update root
            while (Tr.parent != null)
              Tr = Tr.parent;
            t = Tr;
          }
        }
      }
      //update root
      while (Tr.parent != null)
        Tr = Tr.parent;
    }
    if (t != null)
      t.color = Color.BLACK;
  }

  private void link(RBTree<Key,T> u, Key x)
  {
    RBTree<Key, T> v = this;
    if (u != null)
    {
      u.parent = v;
    }
    if (v != null)
    {
      if (x.compareTo(v.key) < 0)
        v.left = u;
      else
        v.right = u;
    }
  }

  private void rotateLeft()
  {
    RBTree<Key,T> x = this;
    RBTree y = x.right;
    RBTree p = x.parent;
    x.right = y.left;
    if (y.left!=null)
      y.left.parent = x;
    y.left = x;
    x.parent = y;
    y.parent = p;
    if (p != null)
    {
      if (p.left == x)
        p.left = y;
      else
        p.right = y;
    }
  }

  private void rotateRight()
  {
    RBTree<Key,T> x = this;
    RBTree y = x.left;
    RBTree p = x.parent;
    x.left = y.right;
    if (y.right != null)
      y.right.parent = x;
    y.right = x;
    x.parent = y;
    y.parent = p;
    if (p != null)
    {
      if (p.left == x)
        p.left = y;
      else
        p.right = y;
    }
  }

  public static void main(String[] args) {
    Random r = new Random();

    RBTree<Integer,Integer> t = new RBTree<Integer,Integer>(r.nextInt(),
                                                            r.nextInt());
    for (int i=0; i<10; i++)
    {
      ArrayList<Integer> nums = new ArrayList<Integer>();
      for (int j=0; j<10000; j++)
      {
        int temp = r.nextInt();
        System.out.println("insert "+temp);
        t = t.insertNode(temp,1);
        t.checkTree();
        nums.add(temp);
      }
      Collections.shuffle(nums);
      for (int it : nums)
      {
        System.out.println("remove "+it);
        t = t.removeNode(it);
        t.checkTree();
      }
    }
  }
}