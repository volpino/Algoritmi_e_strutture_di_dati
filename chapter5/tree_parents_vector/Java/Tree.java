/*
 * Chapter 5
 * Paragraph 4
 *
 * Tree structure (with parents vector) implementation
 */

public class Tree {
  private int p[];

  public Tree(int n) {
    //allocates space for n elements (from 1 to n)
    p = new int[n+1];
    for (int i=1; i<=n; i++)
      p[i] = 0;
  }

  //returns the parent node of i; returns 0 if i is the root
  public int parent(int i) {
    return p[i];
  }

  //makes i child of j
  public void setParent(int i, int j) {
    p[i] = j;
  }

  public static void main(String args[]) {
    Tree t = new Tree(10);

    t.setParent(2,1);
    t.setParent(3,1);
    t.setParent(4,2);
    t.setParent(5,2);
    t.setParent(6,3);
    t.setParent(7,3);
    t.setParent(8,4);
    t.setParent(9,4);
    t.setParent(10,5);
    path_to_root(10,t);
    System.out.println("\n");
    path_to_root(4,t);
  }

  static char a[] = {'*','a','b','c','d','e','f','g','h','i','j'};

  static void path_to_root(int i, Tree t) {
    if (i>0)
    {
      System.out.println(a[i]);
      path_to_root(t.parent(i),t);
    }
  }
}