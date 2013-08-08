/*
 * Chapter 4
 * Paragraph 3
 *
 * Stack data structure implementation
 */

import java.lang.reflect.Array;

public class Stack<T> {
  private T elements[];
  private int n; //cursor
  private int m; //max dimension

  public Stack(Class<T> c, int dim) {
    //allocate space for dim elements with indexes from 1 to dim
    elements = (T[]) Array.newInstance(c, dim+1);
    n = 0;
    m = dim;
  }

  public T top()
  {
    return elements[n];
  }

  public boolean isEmpty()
  {
    return n==0;
  }

  public T pop()
  {
    T t;
    t = elements[n];
    n--;
    return t;
  }

  public void push(T v)
  {
    n++;
    elements[n] = v;
  }

  public static void main(String args[]) {
    Stack<Integer> s = new Stack<Integer>(Integer.class, 10);

    for (int i=0; i<10; i++)
    {
      s.push(i);
    }

    while(!s.isEmpty())
    {
      System.out.println(s.top());
      s.pop();
    }
  }
}