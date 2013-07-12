#ifndef MATRIX_H
#define MATRIX_H

#include "graph.h"
#include <set>
using namespace std;

template <class T>
class MatrixGraph {
public:
  MatrixGraph(int num_vertex) {
    this->num_vertex = num_vertex;
    matrix = new int*[num_vertex];
    for (int i=0; i<num_vertex; i++) {
      matrix[i] = new int[num_vertex];
    }

    for (int i=0; i<num_vertex; i++) {
      for (int j=0; j<num_vertex; j++) {
        matrix[i][j] = 0;
      }
      available_ids.insert(i);
    }

    vertices_ids = new Node<T>*[num_vertex];
  };

  virtual void insertNode(Node<T>* node) {
    if (available_ids.empty()) {
      return;
    }
    node->id = *available_ids.begin();
    available_ids.erase(node->id);
    vertices.insert(node);
    vertices_ids[node->id] = node;
  };

  virtual void insertEdge(Node<T>* a, Node<T>* b) {
    if (vertices.find(a) == vertices.end() || vertices.find(b) == vertices.end()) {
      return;
    }
    matrix[a->id][b->id] = 1;
  };

  virtual void deleteNode(Node<T>* node) {
    if (node->id >= num_vertex || available_ids.find(node->id) != available_ids.end()) {
      return;
    }
    vertices.erase(node);
    for (int i=0; i<num_vertex; i++) {
      matrix[node->id][i] = 0;
      matrix[i][node->id] = 0;
    }
    available_ids.insert(node->id);
  };

  virtual void deleteEdge(Node<T>* a, Node<T>* b) {
    if (vertices.find(a) == vertices.end() || vertices.find(b) == vertices.end()) {
      return;
    }
    matrix[a->id][b->id] = 0;
  };

  virtual set<Node<T>* >* adj(Node<T>* node) {
    if (vertices.find(node) == vertices.end()) {
      return 0;
    }
    set<Node<T>* >* adjacent_set = new set<Node<T>* >();
    for (int i=0; i<num_vertex; i++) {
      if (matrix[node->id][i] != 0) {
        adjacent_set->insert(vertices_ids[i]);
      }
    }

    return adjacent_set;
  };

  virtual set<Node<T>* > v() {
    return vertices;
  };

  ~MatrixGraph() {
    delete[] vertices_ids;
    for (int i=0; i<num_vertex; i++) {
      delete[] matrix[i];
    }
  };

private:
  int num_vertex;
  int** matrix;
  set<Node<T>* > vertices;
  Node<T>** vertices_ids;
  set<int> available_ids;
};

#endif
