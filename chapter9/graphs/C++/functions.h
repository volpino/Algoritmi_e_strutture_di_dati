#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <set>
#include <queue>
using namespace std;

/* Chapter 9
 * Paragraph 5
 */
template<class T>
void visita(Graph<T>& g, Node<T>* r) {
  typedef typename set<Node<T>* >::iterator iter;

  set<Node<T>* > s;
  set<Node<T>* > visited;
  set<Node<T>* >* adj;

  s.insert(r);
  visited.insert(r);

  while (s.size() > 0) {
    Node<T>* u = *(s.begin());
    s.erase(u);
    cout << "Visiting node: " << u->key << "=" << u->value << endl;
    adj = g.adj(u);
    for (iter it=adj->begin(); it != adj->end(); it++) {
      Node<T>* v = *it;
      if (visited.find(v) == visited.end()) {
        visited.insert(v);
        s.insert(v);
      }
    }
    delete adj;
  }
};


/* Chapter 9
 * Paragraph 5.1
 */
template<class T>
void bfs(Graph<T>& g, Node<T>* r) {
  typedef typename set<Node<T>* >::iterator iter;

  queue<Node<T>* > s;
  set<Node<T>* > visited;
  set<Node<T>* >* adj;

  s.push(r);
  visited.insert(r);

  while (!s.empty()) {
    Node<T>* u = s.front();
    s.pop();
    cout << "Visiting node: " << u->key << "=" << u->value << endl;

    adj = g.adj(u);
    for (iter it=adj->begin(); it != adj->end(); it++) {
      Node<T>* v = *it;
      if (visited.find(v) == visited.end()) {
        visited.insert(v);
        s.push(v);
      }
    }
    delete adj;
  }
};


/* Chapter 9
 * Paragraph 5.1
 */
template<class T>
void erdos(Graph<T>& g, Node<T>* r) {
}


/* Chapter 9
 * Paragraph 5.4
 */
template<class T>
void dfs(Graph<T>& g, Node<T>* u) {
  set<Node<T>* > visited;
  dfs_rec(g, u, visited);
}


template<class T>
void dfs_rec(Graph<T>& g, Node<T>* u, set<Node<T>* >& visited) {
  typedef typename set<Node<T>* >::iterator iter;

  visited.insert(u);
  cout << "Visiting node: " << u->key << "=" << u->value << endl;
  set<Node<T>* >* adj = g.adj(u);
  for (iter it=adj->begin(); it != adj->end(); it++) {
    Node<T>* v = *it;
    if (visited.find(v) == visited.end()) {
      visited.insert(v);
      dfs_rec(g, v, visited);
    }
  }
  delete adj;
}

#endif
