/*
 * Chapter 4
 * Paragraph 1
 *
 * List data structure implementation
 */

public class List<T> {
  private List pred;
  private List succ;
  private T value;

  public List()
  {
    this.pred = this;
    this.succ = this;
  }

  public boolean empty()
  {
    return (this.pred == this.succ) && (this.succ == this);
  }

  public List head()
  {
    return this.succ;
  }

  public List tail()
  {
    return this.pred;
  }

  public boolean finished(List p)
  {
    return (p == this);
  }

  public List next(List p)
  {
    return p.succ;
  }

  public List prev(List p)
  {
    return p.pred;
  }

  public T read()
  {
    return this.value;
  }

  public void write(List p, T v)
  {
    p.value = v;
  }

  public List insert(List p, T v)
  {
    List t = new List<T>();
    t.value = v;
    t.pred = p.pred;
    t.pred.succ = t;
    t.succ = p;
    p.pred = t;
    return p;
  }

  public List remove(List p)
  {
    p.pred.succ = p.succ;
    p.succ.pred = p.pred;
    List t = p.succ;
    return t;
  }

  public static void main(String args[]) {
    List<Integer> l = new List<Integer>();

    for (int i=0; i<10; i++)
    {
      l = l.insert(l,i);
    }

    List<Integer> it = l.head();
    while (!l.finished(it))
    {
      l.insert(it,15);
      l.write(it,20);
      it = l.next(it);
    }

    for (it=l.head(); !l.finished(it); it=l.next(it))
    {
      System.out.println(it.read());
    }
    System.out.println("\n");
  }
}