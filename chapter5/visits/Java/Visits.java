/*
 * Chapter 5
 * Paragraph 2
 */

import java.util.LinkedList;

public class Visits {
  static <T> void visitaProfondita(Tree<T> t) {
    System.out.println(t.get_value());
    Tree<T> u = t.leftmostChild();
    while (u != null)
    {
      visitaProfondita(u);
      u = u.rightSibling();
    }
  }

  static <T> void invisita(Tree<T> t, int i) {
    Tree<T> u = t.leftmostChild();
    int k = 0;
    while (u!=null && k<i)
    {
      k++;
      invisita(u, i);
      u = u.rightSibling();
    }
    System.out.println(t.get_value());
    while (u!=null)
    {
      invisita(u, i);
      u = u.rightSibling();
    }
  }

  static <T> void visitaAmpiezza(Tree<T> t) {
    LinkedList<Tree<T>> q = new LinkedList<Tree<T>>();
    q.add(t);
    while (q.size() > 0)
    {
      Tree<T> u = q.removeFirst();
      System.out.println(u.get_value());
      u = u.leftmostChild();
      while (u != null)
      {
        q.add(u);
        u = u.rightSibling();
      }
    }
  }

  public static void main(String args[]) {
    Tree<Integer> t = new Tree(0);
    build_tree(t);

    visitaProfondita(t);
    System.out.println("\n");
    invisita(t, 1);
    System.out.println("\n");
    visitaAmpiezza(t);
  }

  static void build_tree(Tree<Integer> t) {
    if (t.get_value() < 3)
    {
      for (int i=0; i<3; i++)
      {
        Tree<Integer> tmp = new Tree<Integer>(t.get_value()+1);
        build_tree(tmp);
        t.insertChild(tmp);
      }
    }
  }
}
