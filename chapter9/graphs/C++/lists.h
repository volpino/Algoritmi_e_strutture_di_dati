#ifndef LISTS_H
#define LISTS_H

#include "graph.h"
#include <set>
#include <vector>
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
    if (available_ids.empty()) {
      return;
    }
    node->id = *available_ids.begin();
    available_ids.erase(node->id);
    vertices.insert(node);
  };

  virtual void insertEdge(Node<T>* a, Node<T>* b) {
    if (vertices.find(a) == vertices.end() || vertices.find(b) == vertices.end()) {
      return;
    }
    adj_list[a->id].push_back(b);
  };

  virtual void deleteNode(Node<T>* node) {
    if (node->id >= num_vertex || available_ids.find(node->id) != available_ids.end()) {
      return;
    }
    vertices.erase(node);
    adj_list[node->id].clear();
    available_ids.insert(node->id);

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
    for (int i=0; i<adj_list[a->id].size(); i++) {
      if (adj_list[a->id][i] == b) {
        adj_list[a->id].erase(adj_list[a->id].begin()+i);
        break;
      }
    }
  };

  virtual set<Node<T>* >* adj(Node<T>* node) {
    if (vertices.find(node) == vertices.end()) {
      return 0;
    }
    set<Node<T>* >* adjacent_set = new set<Node<T>* >();
    for (int i=0; i<adj_list[node->id].size(); i++) {
      adjacent_set->insert(adj_list[node->id][i]);
    }

    return adjacent_set;
  };

  virtual set<Node<T>* >* v() {
    return &vertices;
  };

  ~ListsGraph() {
  };

private:
  int num_vertex;
  vector<vector<Node<T>* > > adj_list;
  set<Node<T>* > vertices;
  set<int> available_ids;
};

#endif
