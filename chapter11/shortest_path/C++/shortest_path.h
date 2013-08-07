/*
 * Chapter 11
 *
 * Shortest paths algorithms implementation
 */


#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include "../../../chapter9/graphs/C++/lists.h"
#include <queue>
#include <deque>
#include <iostream>

template<class T>
class ShortestPath {
public:
  int* d;
  bool* b;
  Graph<T>* graph;

  void path(Graph<T> &g, Node<T>* r, int* t) {
    typedef typename set<Node<T>* >::iterator iter;

    graph = &g;
    d = new int[g.num_vertex];
    b = new bool[g.num_vertex];

    set<Node<T>* >* vertices = g.v();
    for (iter it=vertices->begin(); it != vertices->end(); it++) {
      t[g.id(*it)] = -1;
      d[g.id(*it)] = -1;
      b[g.id(*it)] = false;
    }

    t[g.id(r)] = -1;
    d[g.id(r)] = 0;
    b[g.id(r)] = true;

    addToStructure(r, 0);

    while (!structureIsEmpty()) {
      Node<T>* u = popFromStructure();
      b[g.id(u)] = false;

      set<Node<T>* >* adj = g.adj(u);

      for (iter it=adj->begin(); it != adj->end(); it++) {
        Node<T>* v = *it;
        if (d[g.id(v)] == -1 || d[g.id(u)] + g.w(u, v) < d[g.id(v)]) {
          if (!b[g.id(v)]) {
            addToStructure(v, d[g.id(u)] + g.w(u, v));
          }
          else {
            alreadySeen(v, d[g.id(u)] + g.w(u ,v));
          }
          t[g.id(v)] = g.id(u);
          d[g.id(v)] = d[g.id(u)] + g.w(u, v);
        }
      }
      delete adj;
    }

    delete[] d;
    delete[] b;
  };

  virtual bool structureIsEmpty() = 0;

  virtual Node<T>* popFromStructure() = 0;

  virtual void addToStructure(Node<T>* node, int weight) = 0;

  virtual void alreadySeen(Node<T>* node, int weight) = 0;
};


template<class T>
class Dijkstra : public ShortestPath<T> {
public:
  priority_queue<Node<T>* > s;

  virtual bool structureIsEmpty() {
    return s.empty();
  }

  virtual Node<T>* popFromStructure() {
    Node<T>* ret = s.top();
    s.pop();
    return ret;
  };

  virtual void addToStructure(Node<T>* node, int weight) {
    node->cost = weight;
    s.push(node);
  };

  virtual void alreadySeen(Node<T>* node, int weight) {
    node->cost = weight;

    // this is inefficient and only for not having to increase the complexity
    // of the code by using a custom priority queue. Unfortunately the STL
    // priority queue does not allow to update the priority of an item.
    priority_queue<Node<T>* > newqueue;
    while (!s.empty()) {
      Node<T>* tmp = s.top();
      s.pop();
      newqueue.push(tmp);
    }
    swap(s, newqueue);
  };
};


template<class T>
class BellmanFord : public ShortestPath<T> {
public:
  queue<Node<T>* > s;

  virtual bool structureIsEmpty() {
    return s.empty();
  }

  virtual Node<T>* popFromStructure() {
    Node<T>* ret = s.front();
    s.pop();
    return ret;
  };

  virtual void addToStructure(Node<T>* node, int weight) {
    s.push(node);
  };

  virtual void alreadySeen(Node<T>* node, int weight) {
  };
};


template<class T>
class PapeDEsopo : public ShortestPath<T> {
public:
  deque<Node<T>* > s;

  virtual bool structureIsEmpty() {
    return s.empty();
  }

  virtual Node<T>* popFromStructure() {
    Node<T>* ret = *(s.begin());
    s.pop_front();
    return ret;
  };

  virtual void addToStructure(Node<T>* node, int weight) {
    if (this->d[this->graph->id(node)] == -1) {
      s.push_back(node);
    }
    else {
      s.push_front(node);
    }
  };

  virtual void alreadySeen(Node<T>* node, int weight) {
  };
};



#endif
