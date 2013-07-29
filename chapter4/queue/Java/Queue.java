/*
 * Chapter 4
 * Paragraph 3
 *
 * Queue data structure implementation
 */

import java.lang.reflect.Array;

public class Queue<T> {
  private int dim;
  private T elements[];
  private int n; //current dimension
  private int head;
  private int m; //max dimension

  public Queue(Class<T> c, int dim) {
    elements = (T[]) Array.newInstance(c, dim);
    m = dim;
    head = 0;
    n = 0;
  }

  public T top()
  {
    return elements[head];
  }

  public boolean isEmpty()
  {
    return n==0;
  }

  public T dequeue()
  {
    T t = elements[head];
    head = (head+1) % m;
    n--;
    return t;
  }

  public void enqueue(T v)
  {
    elements[(head+n) % m] = v;
    n++;
  }

  public static void main(String args[]) {
    Queue<Integer> q = new Queue<Integer>(Integer.class, 10);

    for (int i=0; i<10; i++)
    {
      q.enqueue(i);
    }

    while(!q.isEmpty())
    {
      System.out.println(q.top());
      q.dequeue();
    }
  }
}