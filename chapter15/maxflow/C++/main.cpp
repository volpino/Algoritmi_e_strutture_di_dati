#include <iostream>
#include "flow.h"
#include "../../../chapter09/graphs/C++/matrix.h"

int main()
{
  // Create a graph with 6 nodes
  int n=6;
  MatrixGraph<int> G = MatrixGraph<int>(n);
  Node<int>* n1 = new Node<int>(1, 1);
  Node<int>* n2 = new Node<int>(2, 2);
  Node<int>* n3 = new Node<int>(3, 3);
  Node<int>* n4 = new Node<int>(4, 4);
  Node<int>* n5 = new Node<int>(5, 5);
  Node<int>* n6 = new Node<int>(6, 6);
  G.insertNode(n1);
  G.insertNode(n2);
  G.insertNode(n3);
  G.insertNode(n4);
  G.insertNode(n5);
  G.insertNode(n6);

  //Add edges
  G.insertEdge(n1,n2,2);
  G.insertEdge(n1,n3,25);
  G.insertEdge(n2,n4,5);
  G.insertEdge(n2,n3,8);
  G.insertEdge(n2,n5,11);
  G.insertEdge(n3,n4,7);
  G.insertEdge(n3,n5,6);
  G.insertEdge(n4,n6,25);
  G.insertEdge(n5,n6,35);

  // Create an empty flow
  int **f = new int*[G.num_vertex];
  for (int i=0; i<G.num_vertex; i++)
    f[i] = new int[G.num_vertex];

  maxFlow(G,G.id(n1),G.id(n6),f);

  for (int i=0; i<G.num_vertex; i++)
  {
    for (int j=0; j<G.num_vertex; j++)
      cout << f[i][j] << " ";
    cout << endl;
  }

  return 0;
}
