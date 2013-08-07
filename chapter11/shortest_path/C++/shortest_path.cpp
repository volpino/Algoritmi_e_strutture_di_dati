#include "shortest_path.h"
#include <iostream>

using namespace std;

int main() {
  ListsGraph<int> g = ListsGraph<int>(10);
  Node<int>* node1 = new Node<int>(1, 1);
  Node<int>* node2 = new Node<int>(2, 2);
  Node<int>* node3 = new Node<int>(3, 3);
  Node<int>* node4 = new Node<int>(4, 4);
  Node<int>* node5 = new Node<int>(5, 5);
  Node<int>* node6 = new Node<int>(6, 6);

  g.insertNode(node1);
  g.insertNode(node2);
  g.insertNode(node3);
  g.insertNode(node4);
  g.insertNode(node5);
  g.insertNode(node6);

  for (int i=0; i<1; i++) g.insertEdge(node1, node2);
  for (int i=0; i<2; i++) g.insertEdge(node1, node3);

  for (int i=0; i<1; i++) g.insertEdge(node2, node5);

  for (int i=0; i<3; i++) g.insertEdge(node3, node2);
  for (int i=0; i<3; i++) g.insertEdge(node3, node4);

  for (int i=0; i<2; i++) g.insertEdge(node4, node6);

  for (int i=0; i<2; i++) g.insertEdge(node5, node4);
  for (int i=0; i<5; i++) g.insertEdge(node5, node6);


  int t[10];

  cout << "Dijkstra:" << endl;
  Dijkstra<int> dijkstra;
  dijkstra.path(g, node1, t);

  cout << "Vector of parents: ";
  for (int i=0; i<6; i++) {
    cout << t[i] << " ";
  }
  cout << endl;

  cout << "Node 1: "<< node1->cost << endl;
  cout << "Node 2: "<< node2->cost << endl;
  cout << "Node 3: "<< node3->cost << endl;
  cout << "Node 4: "<< node4->cost << endl;
  cout << "Node 5: "<< node5->cost << endl;
  cout << "Node 6: "<< node6->cost << endl;


  cout << endl;
  cout << "BellmanFord:" << endl;
  BellmanFord<int> bf;
  bf.path(g, node1, t);

  cout << "Vector of parents: ";
  for (int i=0; i<6; i++) {
    cout << t[i] << " ";
  }
  cout << endl;

  cout << "Node 1: "<< node1->cost << endl;
  cout << "Node 2: "<< node2->cost << endl;
  cout << "Node 3: "<< node3->cost << endl;
  cout << "Node 4: "<< node4->cost << endl;
  cout << "Node 5: "<< node5->cost << endl;
  cout << "Node 6: "<< node6->cost << endl;


  cout << endl;
  cout << "Pape D'Esopo:" << endl;
  PapeDEsopo<int> pe;
  pe.path(g, node1, t);

  cout << "Vector of parents: ";
  for (int i=0; i<6; i++) {
    cout << t[i] << " ";
  }
  cout << endl;

  cout << "Node 1: "<< node1->cost << endl;
  cout << "Node 2: "<< node2->cost << endl;
  cout << "Node 3: "<< node3->cost << endl;
  cout << "Node 4: "<< node4->cost << endl;
  cout << "Node 5: "<< node5->cost << endl;
  cout << "Node 6: "<< node6->cost << endl;

}
