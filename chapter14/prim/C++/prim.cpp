/*
 * Chapter 14
 * Paragraph 3.2
 *
 * Prim minimum spanning tree algorithm
 */

#include "../../../chapter09/graphs/C++/graph.h"
#include "../../../chapter09/graphs/C++/matrix.h"
#include "../../../chapter10/priorityqueue_heap/C++/heap.h"
#include <climits>
#include <iostream>

using namespace std;


template <class T>
void prim(Graph<T> &g, Node<T>* r, int p[]) {
  HeapQueue<Node<T>* > q(g.num_vertex);

  HeapItem<Node<T>* >** pos = new HeapItem<Node<T>* >*[g.num_vertex];

  for (typename Graph<T>::iterator it=g.v()->begin(); it!=g.v()->end(); it++) {
    if ((*it) != r) {
      pos[g.id(*it)] = q.insert(*it, INT_MAX);
    }
  }

  pos[g.id(r)] = q.insert(r, 0);
  p[g.id(r)] = 0;

  while (q.size() != 0) {
    Node<T>* u = q.min();
    q.deleteMin();

    pos[g.id(u)] = 0;

    set<Node<T>* >* adj = g.adj(u);
    for (typename Graph<T>::iterator it=adj->begin(); it!=adj->end(); it++) {
      if (pos[g.id(*it)] != 0 && g.w(u, *it) < pos[g.id(*it)]->priority) {
        q.decrease(pos[g.id(*it)], g.w(u, *it));
        p[g.id(*it)] = g.id(u);
      }
    }
  }
}


int main() {
  MatrixGraph<int> g = MatrixGraph<int>(10);

  Node<int>* node1 = new Node<int>(1, 1);
  Node<int>* node2 = new Node<int>(2, 2);
  Node<int>* node3 = new Node<int>(3, 3);
  Node<int>* node4 = new Node<int>(4, 4);
  Node<int>* node5 = new Node<int>(5, 5);
  Node<int>* node6 = new Node<int>(6, 6);
  Node<int>* node7 = new Node<int>(7, 7);

  g.insertNode(node1);
  g.insertNode(node2);
  g.insertNode(node3);
  g.insertNode(node4);
  g.insertNode(node5);
  g.insertNode(node6);
  g.insertNode(node7);

  g.insertEdge(node1, node2, 9);
  g.insertEdge(node2, node1, 9);

  g.insertEdge(node1, node3, 6);
  g.insertEdge(node3, node1, 6);

  g.insertEdge(node2, node3, 11);
  g.insertEdge(node3, node2, 11);

  g.insertEdge(node2, node4, 5);
  g.insertEdge(node4, node2, 5);

  g.insertEdge(node2, node5, 20);
  g.insertEdge(node5, node2, 20);

  g.insertEdge(node3, node4, 2);
  g.insertEdge(node4, node3, 2);

  g.insertEdge(node3, node6, 18);
  g.insertEdge(node6, node3, 18);

  g.insertEdge(node4, node5, 13);
  g.insertEdge(node5, node4, 13);

  g.insertEdge(node4, node6, 28);
  g.insertEdge(node6, node4, 28);

  g.insertEdge(node4, node7, 15);
  g.insertEdge(node7, node4, 15);

  g.insertEdge(node5, node7, 3);
  g.insertEdge(node7, node5, 3);

  g.insertEdge(node6, node7, 25);
  g.insertEdge(node7, node6, 25);

  int* p = new int[g.num_vertex];
  for (int i=0; i<g.num_vertex; i++) {
    p[i] = -1;
  }

  prim(g, node1, p);

  cout << "Node 1: " << g.id(node1) << endl;
  cout << "Node 2: " << g.id(node2) << endl;
  cout << "Node 3: " << g.id(node3) << endl;
  cout << "Node 4: " << g.id(node4) << endl;
  cout << "Node 5: " << g.id(node5) << endl;
  cout << "Node 6: " << g.id(node6) << endl;
  cout << "Node 7: " << g.id(node7) << endl;

  for (int i=1; i<g.num_vertex; i++) {
    if (p[i] != -1) {
      cout << i+1 << " - " << p[i]+1 << endl;
    }
  }
}
