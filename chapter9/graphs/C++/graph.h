#ifndef GRAPH_H
#define GRAPH_H

#include <set>

template <class T>
class Node {
public:
  T key;
  T value;
  T id;

  Node(T k, T v) {
    key = k;
    value = v;
  };
};

template <class T>
class Graph {
public:
  virtual void insertNode(Node<T>*) = 0;
  virtual void insertEdge(Node<T>*, Node<T>*) = 0;
  virtual void deleteNode(Node<T>*) = 0;
  virtual void deleteEdge(Node<T>*, Node<T>*) = 0;
  virtual std::set<Node<T>* > adj() = 0;
  virtual std::set<Node<T>* > v() = 0;
};

#endif
