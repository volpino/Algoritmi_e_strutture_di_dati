/*
 * Chapter 5
 * Paragraph 4
 *
 * Tree data structure implementation (pointers to parent, child and sibling)
 */

public class Tree<T> {
  T value;
  Tree parent;
  Tree child;
  Tree sibling;

  public Tree(T v) {
    value = v;
    parent = null;
    child = null;
    sibling = null;
  }

  public void insertChild(Tree t)
  {
    t.parent = this;
    t.sibling = child;
    child = t;
  }

  public void insertSibling(Tree t)
  {
    t.parent = parent;
    t.sibling = sibling;
    sibling = t;
  }

  public void deleteChild()
  {
    if (child != null)
    {
      child = child.sibling;;
    }
  }

  public void deleteSibling()
  {
    if (sibling != null)
    {
      sibling = sibling.sibling;
    }
  }

  public static void main(String args[])
  {
    Tree<Integer> t = new Tree(0);
    build_tree(t, 3);
    print_tree(t);
  }

  static void build_tree(Tree t, int depth)
  {
    if (depth > 0)
    {
      for (int i=0; i<3; i++)
      {
        Tree<Integer> tmp = new Tree<Integer>(depth);
        build_tree(tmp, depth-1);
        t.insertChild(tmp);
      }
    }
  }

  static void print_tree(Tree t)
  {
    System.out.println(t.value);
    if (t.sibling != null)
      print_tree(t.sibling);
    if (t.child != null)
      print_tree(t.child);
  }
}