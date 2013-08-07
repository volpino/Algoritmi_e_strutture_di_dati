#ifndef GRAPH_H
#define GRAPH_H

#include <set>

template <class T>
class Node {
public:
  T key;
  T value;
  int cost;

  Node(T k, T v) {
    key = k;
    value = v;
    cost = 0;
  };

  // used for shortest paths algorithms
  bool operator() (const Node<T>& a, const Node<T>& b) {
    return a.count < b.count;
  }
};

template <class T>
class Graph {
public:
  virtual void insertNode(Node<T>*) = 0;
  virtual void insertEdge(Node<T>*, Node<T>*) = 0;
  virtual void deleteNode(Node<T>*) = 0;
  virtual void deleteEdge(Node<T>*, Node<T>*) = 0;
  virtual std::set<Node<T>* >* adj(Node<T>*) = 0;
  virtual std::set<Node<T>* >* v() = 0;
  virtual int id(Node<T>*) = 0;
  virtual int w(Node<T>*, Node<T>*) = 0;

  int num_vertex;
};

#endif
