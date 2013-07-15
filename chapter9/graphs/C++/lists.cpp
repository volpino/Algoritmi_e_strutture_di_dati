#include "lists.h"
#include "functions.h"
#include <iostream>

using namespace std;

int main() {
  ListsGraph<int> g = ListsGraph<int>(100);
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
  g.insertEdge(a, c);
  g.deleteEdge(a, d);
  g.deleteEdge(a, b);
  g.insertEdge(a, b);
  g.insertEdge(a, d);
  g.insertEdge(d, c);

  cout << "Simple visit: " << endl;
  visita(g, a);
  cout << endl << endl;

  cout << "BFS: " << endl;
  bfs(g, a);
  cout << endl << endl;

  cout << "DFS: " << endl;
  dfs(g, a);
  cout << endl << endl;

  cout << "Vicini del nodo 1:";
  set<Node<int>* >* a_adj = g.adj(a);
  for (set<Node<int>* >::iterator it=a_adj->begin(); it != a_adj->end(); it++) {
    cout << ' ' << (*it)->key;
  }
  cout << '\n';
  delete a_adj;

  cout << "Vicini del nodo 2:";
  set<Node<int>* >* b_adj = g.adj(b);
  for (set<Node<int>* >::iterator it=b_adj->begin(); it != b_adj->end(); it++) {
    cout << ' ' << (*it)->key;
  }
  cout << '\n';
  delete b_adj;

  cout << "Vicini del nodo 4:";
  set<Node<int>* >* d_adj = g.adj(d);
  for (set<Node<int>* >::iterator it=d_adj->begin(); it != d_adj->end(); it++) {
    cout << ' ' << (*it)->key;
  }
  cout << '\n';
  delete d_adj;

  g.deleteEdge(a, c);
  g.deleteNode(d);

  cout << "Vicini del nodo 1:";
  a_adj = g.adj(a);
  for (set<Node<int>* >::iterator it=a_adj->begin(); it != a_adj->end(); it++) {
    cout << ' ' << (*it)->key;
  }
  cout << '\n';
  delete a_adj;
}
