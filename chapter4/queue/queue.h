#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>

template <class T>
class Queue {
public:
  Queue(int);

  T top();

  bool isEmpty();

  T dequeue();

  void enqueue(T);

  ~Queue();

private:
  T* elements;
  int n; //current dimension
  int head;
  int m; //max dimension
};

template <class T>
Queue<T>::Queue(int dim) : m(dim), head(0), n(0)
{
  elements = new T[dim];
}

template <class T>
T Queue<T>::top()
{
  assert(n>0);
  return elements[head];
}

template <class T>
bool Queue<T>::isEmpty()
{
  return n==0;
}

template <class T>
T Queue<T>::dequeue()
{
  assert(n>0);
  T t = elements[head];
  head = (head+1) % m;
  n--;
  return t;
}

template <class T>
void Queue<T>::enqueue(T v)
{
  assert(n<m);
  elements[(head+n) % m] = v;
  n++;
}

template <class T>
Queue<T>::~Queue()
{
  delete[] elements;
}

#endif
