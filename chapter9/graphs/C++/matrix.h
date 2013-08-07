#ifndef MATRIX_H
#define MATRIX_H

#include "graph.h"
#include <set>
#include <map>
using namespace std;

template <class T>
class MatrixGraph : public Graph<T> {
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
    node_ids[node] = *available_ids.begin();
    available_ids.erase(id(node));
    vertices.insert(node);
    vertices_ids[id(node)] = node;
  };

  virtual void insertEdge(Node<T>* a, Node<T>* b) {
    if (vertices.find(a) == vertices.end() || vertices.find(b) == vertices.end()) {
      return;
    }
    matrix[id(a)][id(b)]++;
  };

  virtual void deleteNode(Node<T>* node) {
    if (id(node) >= this->num_vertex || available_ids.find(id(node)) != available_ids.end()) {
      return;
    }
    vertices.erase(node);
    for (int i=0; i<this->num_vertex; i++) {
      matrix[id(node)][i] = 0;
      matrix[i][id(node)] = 0;
    }
    available_ids.insert(id(node));
  };

  virtual void deleteEdge(Node<T>* a, Node<T>* b) {
    if (vertices.find(a) == vertices.end() || vertices.find(b) == vertices.end()) {
      return;
    }
    if (matrix[id(a)][id(b)] > 0) {
      matrix[id(a)][id(b)]--;
    }
  };

  virtual set<Node<T>* >* adj(Node<T>* node) {
    if (vertices.find(node) == vertices.end()) {
      return 0;
    }
    set<Node<T>* >* adjacent_set = new set<Node<T>* >();
    for (int i=0; i<this->num_vertex; i++) {
      if (matrix[id(node)][i] != 0) {
        adjacent_set->insert(vertices_ids[i]);
      }
    }

    return adjacent_set;
  };

  virtual set<Node<T>* >* v() {
    return &vertices;
  };

  virtual int id(Node<T>* node) {
    return node_ids[node];
  };

  virtual int w(Node<T>* a, Node<T>* b) {
    return matrix[id(a)][id(b)];
  }

  ~MatrixGraph() {
    delete[] vertices_ids;
    for (int i=0; i<this->num_vertex; i++) {
      delete[] matrix[i];
    }
  };

private:
  int** matrix;
  set<Node<T>* > vertices;
  Node<T>** vertices_ids;
  set<int> available_ids;
  map<Node<T>*, int> node_ids;
};

#endif
