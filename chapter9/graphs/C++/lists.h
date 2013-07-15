#ifndef LISTS_H
#define LISTS_H

#include "graph.h"
#include <set>
#include <vector>
#include <map>
using namespace std;

template <class T>
class ListsGraph : public Graph<T> {
public:
  ListsGraph(int num_vertex) {
    this->num_vertex = num_vertex;
    adj_list.resize(num_vertex);

    for (int i=0; i<num_vertex; i++) {
      available_ids.insert(i);
    }
  };

  virtual void insertNode(Node<T>* node) {
    if (available_ids.empty() || vertices.find(node) != vertices.end()) {
      return;
    }
    node_ids[node] = *available_ids.begin();
    available_ids.erase(id(node));
    vertices.insert(node);
  };

  virtual void insertEdge(Node<T>* a, Node<T>* b) {
    if (vertices.find(a) == vertices.end() || vertices.find(b) == vertices.end()) {
      return;
    }
    adj_list[id(a)].push_back(b);
  };

  virtual void deleteNode(Node<T>* node) {
    if (id(node) >= this->num_vertex || available_ids.find(id(node)) != available_ids.end()) {
      return;
    }
    vertices.erase(node);
    adj_list[id(node)].clear();
    available_ids.insert(id(node));

    // removing incoming edges
    for (int i=0; i<adj_list.size(); i++) {
      for (int j=0; j<adj_list[i].size(); j++) {
        if (adj_list[i][j] == node) {
          adj_list[i].erase(adj_list[i].begin() + j);
          if (j < adj_list[i].size()) {
            j--;  // retry with the same index if it's still in the vector
          }
        }
      }
    }
  };

  virtual void deleteEdge(Node<T>* a, Node<T>* b) {
    if (vertices.find(a) == vertices.end() || vertices.find(b) == vertices.end()) {
      return;
    }
    for (int i=0; i<adj_list[id(a)].size(); i++) {
      if (adj_list[id(a)][i] == b) {
        adj_list[id(a)].erase(adj_list[id(a)].begin()+i);
        break;
      }
    }
  };

  virtual set<Node<T>* >* adj(Node<T>* node) {
    if (vertices.find(node) == vertices.end()) {
      return 0;
    }
    set<Node<T>* >* adjacent_set = new set<Node<T>* >();
    for (int i=0; i<adj_list[id(node)].size(); i++) {
      adjacent_set->insert(adj_list[id(node)][i]);
    }

    return adjacent_set;
  };

  virtual set<Node<T>* >* v() {
    return &vertices;
  };

  virtual int id(Node<T>* node) {
    return node_ids[node];
  };

  ~ListsGraph() {
  };

private:
  vector<vector<Node<T>* > > adj_list;
  set<Node<T>* > vertices;
  set<int> available_ids;
  map<Node<T>*, int> node_ids;
};

#endif
