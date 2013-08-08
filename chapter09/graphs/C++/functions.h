#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "lists.h"
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stack>
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
 * Paragraph 5.2
 */
template<class T>
void erdos(Graph<T>& g, Node<T>* r, int* erdos_numbers, Node<T>** paths) {
  typedef typename set<Node<T>* >::iterator iter;

  queue<Node<T>* > s;
  set<Node<T>* >* adj;

  s.push(r);

  for (int i=0; i<g.num_vertex; i++) {
    erdos_numbers[i] = -1;
    paths[i] = 0;
  }
  erdos_numbers[g.id(r)] = 0;

  while (!s.empty()) {
    Node<T>* u = s.front();
    s.pop();

    adj = g.adj(u);
    for (iter it=adj->begin(); it != adj->end(); it++) {
      Node<T>* v = *it;
      if (erdos_numbers[g.id(v)] == -1) {
        erdos_numbers[g.id(v)] = erdos_numbers[g.id(u)] + 1;
        paths[g.id(v)] = u;
        s.push(v);
      }
    }
    delete adj;
  }
}


/* Chapter 9
 * Paragraph 5.3
 */
template<class T>
void stampaCammino(Graph<T>& g, Node<T>* r, Node<T>*s, Node<T>** paths) {
  if (r == s) {
    cout << "Nodo " << r->key << "=" << r->value << endl;
  }
  else if (paths[g.id(s)] == 0) {
    cout << "Nessun cammino da r a s" << endl;
  }
  else {
    stampaCammino(g, r, paths[g.id(s)], paths);
    cout << "Nodo " << s->key << "=" << s->value << endl;
  }
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


/* Chapter 9
 * Paragraph 5.5
 *
 * id is the output, it's a map with nodes as keys and the id of the
 * connected component as value
 */
template<class T>
void cc(Graph<T>& g, vector<Node<T>* >& ordine, map<Node<T>*, int>& id) {
  typedef typename set<Node<T>* >::iterator iter;

  set<Node<T>* >* v = g.v();
  for (iter it=v->begin(); it != v->end(); it++) {
    id[(*it)] = 0;
  }
  int conta = 0;

  for (int i=0; i<ordine.size(); i++) {
    if (id[ordine[i]] == 0) {
      conta++;
      ccdfs(g, conta, ordine[i], id);
    }
  }
}

template<class T>
void ccdfs(Graph<T>& g, int conta, Node<T>* u, map<Node<T>*, int>& id) {
  typedef typename set<Node<T>* >::iterator iter;
  id[u] = conta;

  set<Node<T>* >* adj = g.adj(u);
  for (iter it=adj->begin(); it != adj->end(); it++) {
    Node<T>* v = *it;
    if (id[v] == 0) {
      ccdfs(g, conta, v, id);
    }
  }
  delete adj;
}


/* Chapter 9
 * Paragraph 5.7
 */
template<class T>
bool is_ciclico(Graph<T>& g) {
  typedef typename set<Node<T>* >::iterator iter;
  set<Node<T>* >* v = g.v();
  int* dt = new int[g.num_vertex];
  int* ft = new int[g.num_vertex];

  for (iter it=v->begin(); it != v->end(); it++) {
    for (int i=0; i<g.num_vertex; i++) {
      dt[i] = 0;
      ft[i] = 0;
    }
    if (ciclico(g, *it, 0, dt, ft)) {
      delete[] dt;
      delete[] ft;
      return true;
    }
  }

  delete[] dt;
  delete[] ft;
  return false;
}

template<class T>
bool ciclico(Graph<T>& g, Node<T>* u, int time, int* dt, int * ft) {
  typedef typename set<Node<T>* >::iterator iter;

  time++;
  dt[g.id(u)] = time;

  set<Node<T>* >* adj = g.adj(u);
  for (iter it=adj->begin(); it != adj->end(); it++) {
    Node<T>* v = *it;
    if (dt[g.id(v)] == 0) {
      if (ciclico(g, v, time, dt, ft)) {
        return true;
      }
    }
    else if (dt[g.id(u)] > dt[g.id(v)] && ft[g.id(v)] == 0) {
      return true;
    }
  }
  delete adj;
  time++;
  ft[g.id(u)] = time;

  return false;
}


/* Chapter 9
 * Paragraph 5.7
 */
template<class T>
void dfs_stack(Graph<T>& g, set<Node<T>* >& visited, stack<Node<T>* >& s, Node<T>* u) {
  typedef typename set<Node<T>* >::iterator iter;

  visited.insert(u);

  set<Node<T>* >* adj = g.adj(u);
  for (iter it=adj->begin(); it != adj->end(); it++) {
    Node<T>* v = *it;
    if (visited.find(v) == visited.end()) {
      dfs_stack(g, visited, s, v);
    }
  }
  delete adj;
  s.push(u);
}


template<class T>
void scc(Graph<T>& g, map<Node<T>*, int>& id) {
  typedef typename set<Node<T>* >::iterator iter;

  stack<Node<T>* > s;
  set<Node<T>* > visited;

  set<Node<T>* >* vertices = g.v();
  for (iter it=vertices->begin(); it != vertices->end(); it++) {
    Node<T>* v = *it;
    dfs_stack(g, visited, s, v);
  }

  ListsGraph<T> gt = ListsGraph<T>(g.num_vertex);
  for (iter it=vertices->begin(); it != vertices->end(); it++) {
    gt.insertNode(*it);
  }

  for (iter it=vertices->begin(); it != vertices->end(); it++) {
    Node<T>* u = *it;
    set<Node<T>* >* adj = g.adj(u);
    for (iter innit=adj->begin(); innit != adj->end(); innit++) {
      Node<T>* v = *innit;
      gt.insertEdge(v, u);
    }
    delete adj;
  }

  vector<Node<T>* > ordine;
  for (int i=0; i<s.size(); i++) {
    ordine.push_back(s.top());
    s.pop();
  }

  cc(gt, ordine, id);
}


template<class T>
void topSort(Graph<T>& g, vector<Node<T>* >& ordine) {
  typedef typename set<Node<T>* >::iterator iter;
  set<Node<T>* > visited;

  set<Node<T>* >* v = g.v();
  for (iter it=v->begin(); it != v->end(); it++) {
    Node<T>* u = *it;
    if (visited.find(u) == visited.end()) {
      ts_dfs(g, u, visited, ordine);
    }
  }
}

template<class T>
void ts_dfs(Graph<T>& g, Node<T>* u, set<Node<T>* >& visited, vector<Node<T>* >& ordine) {
  typedef typename set<Node<T>* >::iterator iter;

  visited.insert(u);

  set<Node<T>* >* adj = g.adj(u);
  for (iter it=adj->begin(); it != adj->end(); it++) {
    Node<T>* v = *it;
    if (visited.find(v) == visited.end()) {
      ts_dfs(g, v, visited, ordine);
    }
  }
  delete adj;

  ordine.push_back(u);
}
#endif
