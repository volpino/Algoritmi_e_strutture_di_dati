/*
 * LICENSE
 */

#ifndef STACK_H
#define STACK_H

#include <cassert>

template <class T>
class Stack {
public:
  Stack(int);

  T top();

  bool isEmpty();

  T pop();

  void push(T);

  ~Stack();

private:
  T* elements;
  int n; //cursor
  int m; //max dimension
};

template <class T>
Stack<T>::Stack(int dim) : n(0), m(dim)
{
  //allocate space for dim elements with indexes from 1 to dim
  elements = new T[dim+1];
}

template <class T>
T Stack<T>::top()
{
  assert(n>0);
  return elements[n];
}

template <class T>
bool Stack<T>::isEmpty()
{
  return n==0;
}

template <class T>
T Stack<T>::pop()
{
  assert(n>0);
  T t;
  t = elements[n];
  n--;
  return t;
}

template <class T>
void Stack<T>::push(T v)
{
  assert(n<m);
  n++;
  elements[n] = v;
}

template <class T>
Stack<T>::~Stack()
{
  delete[] elements;
}

#endif
