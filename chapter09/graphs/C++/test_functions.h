#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include "functions.h"
#include <iostream>

using namespace std;

template <class T>
void test_functions(Graph<T>& g) {
  Node<int>* a = new Node<int>(1, 1);
  Node<int>* b = new Node<int>(2, 2);
  Node<int>* c = new Node<int>(3, 3);
  Node<int>* d = new Node<int>(4, 4);
  g.insertNode(a);
  g.insertNode(b);
  g.insertNode(c);
  g.deleteNode(c);
  g.insertNode(d);
  g.insertNode(c);

  g.insertEdge(a, b);
  g.deleteEdge(a, d);
  g.deleteEdge(a, b);

  g.insertEdge(a, b);
  g.insertEdge(a, c);
  g.insertEdge(a, d);
  g.insertEdge(b, c);
  g.insertEdge(c, a);
  g.insertEdge(d, c);
  g.insertEdge(d, b);

  cout << "Simple visit: " << endl;
  visita(g, a);
  cout << endl << endl;

  cout << "BFS: " << endl;
  bfs(g, a);
  cout << endl << endl;

  cout << "DFS: " << endl;
  dfs(g, a);
  cout << endl << endl;

  cout << "Erdos: " << endl;
  Node<int>** paths = new Node<int>*[g.num_vertex];
  int* erdos_numbers = new int[g.num_vertex];
  erdos(g, c, erdos_numbers, paths);
  for (int i=0; i<g.num_vertex; i++) {
    cout << erdos_numbers[i] << ' ';
  }
  cout << endl << endl;


  cout << "stampaCammino" << endl;
  stampaCammino(g, c, d, paths);
  cout << endl << endl;

  delete[] paths;
  delete[] erdos_numbers;

  cout << "Ciclico?: " << (is_ciclico(g) ? "Yes" : "No") << endl;
  cout << endl << endl;

  cout << "Vicini del nodo 1 " << a << " :";
  set<Node<int>* >* a_adj = g.adj(a);
  for (set<Node<int>* >::iterator it=a_adj->begin(); it != a_adj->end(); it++) {
    cout << ' ' << (*it)->key;
  }
  cout << endl;
  delete a_adj;

  cout << "Vicini del nodo 2 " << b << " :";
  set<Node<int>* >* b_adj = g.adj(b);
  for (set<Node<int>* >::iterator it=b_adj->begin(); it != b_adj->end(); it++) {
    cout << ' ' << (*it)->key;
  }
  cout << endl;
  delete b_adj;

  cout << "Vicini del nodo 3 " << c << " :";
  set<Node<int>* >* c_adj = g.adj(c);
  for (set<Node<int>* >::iterator it=c_adj->begin(); it != c_adj->end(); it++) {
    cout << ' ' << (*it)->key;
  }
  cout << endl;
  delete c_adj;

  cout << "Vicini del nodo 4 " << d << " :";
  set<Node<int>* >* d_adj = g.adj(d);
  for (set<Node<int>* >::iterator it=d_adj->begin(); it != d_adj->end(); it++) {
    cout << ' ' << (*it)->key;
  }
  cout << endl << endl;
  delete d_adj;

  cout << "SCC: " << endl;
  map<Node<int>*, int> scc_id;
  scc(g, scc_id);
  for (map<Node<int>*, int>::iterator it=scc_id.begin(); it!=scc_id.end(); it++) {
    cout << "Node " << it->first->key << "=" << it->first->value << " => " << it->second << endl;
  }
  cout << endl << endl;

  cout << "TopSort: " << endl;
  vector<Node<int>* > ordine;
  topSort(g, ordine);
  for (int i=0; i<ordine.size(); i++) {
    cout << "Node " << ordine[i]->key << "=" << ordine[i]->value << endl;
  }
  cout << endl << endl;

  g.deleteEdge(a, c);
  g.deleteNode(d);

  cout << "Vicini del nodo 1:";
  a_adj = g.adj(a);
  for (set<Node<int>* >::iterator it=a_adj->begin(); it != a_adj->end(); it++) {
    cout << ' ' << (*it)->key;
  }
  cout << endl;
  delete a_adj;
}

#endif
