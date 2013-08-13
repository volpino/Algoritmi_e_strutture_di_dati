/*
 *
 * Chapter 13
 * Paragraph 5
 *
 */

#include "../../../chapter09/graphs/C++/graph.h"
#include "../../../chapter09/graphs/C++/matrix.h"
#include <climits>
#include <iostream>

#define MAX_N 100

using namespace std;

int d[MAX_N][MAX_N];
int p[MAX_N][MAX_N];

template <class T>
void floydWarshall(Graph<T>& G)
{
  for (typename Graph<T>::iterator i=G.v()->begin(); i!=G.v()->end(); i++)
  {
    int u = G.id(*i);
    for (typename Graph<T>::iterator j=G.v()->begin(); j!=G.v()->end(); j++)
    {
      int v = G.id(*j);
      if (u==v)
        d[u][v] = 0;
      else
        d[u][v] = INT_MAX;
      p[u][v] = 0;
    }
  }
  for (typename Graph<T>::iterator i=G.v()->begin(); i!=G.v()->end(); i++)
  {
    int u = G.id(*i);
    std::set<Node<T>* >* adj = G.adj(*i);
    for (typename Graph<T>::iterator j=adj->begin(); j!=adj->end(); j++)
    {
      int v = G.id(*j);
      d[u][v] = G.w(*i,*j);
      p[u][v] = u+1;
    }
    delete adj;
  }
  for (int k=0; k<G.num_vertex; k++)
  {
    for (typename Graph<T>::iterator i=G.v()->begin(); i!=G.v()->end(); i++)
    {
      int u = G.id(*i);
      for (typename Graph<T>::iterator j=G.v()->begin(); j!=G.v()->end(); j++)
      {
        int v = G.id(*j);
        if (d[u][k]!=INT_MAX && d[k][v]!=INT_MAX && d[u][k] + d[k][v] < d[u][v])
        {
          d[u][v] = d[u][k] + d[k][v];
          p[u][v] = p[k][v];
        }
      }
    }
  }
}

int main()
{
  int n = 4;
  MatrixGraph<int> g = MatrixGraph<int>(n);
  Node<int>* n1 = new Node<int>(1, 1);
  Node<int>* n2 = new Node<int>(2, 2);
  Node<int>* n3 = new Node<int>(3, 3);
  Node<int>* n4 = new Node<int>(4, 4);
  Node<int>* n5 = new Node<int>(5, 5);

  g.insertNode(n1);
  g.insertNode(n2);
  g.insertNode(n3);
  g.insertNode(n4);
  g.insertNode(n5);

  g.insertEdge(n1, n2, 5);
  g.insertEdge(n1, n3, 2);
  g.insertEdge(n2, n3, 3);
  g.insertEdge(n2, n4, 4);
  g.insertEdge(n3, n4, 5);
  g.insertEdge(n4, n2, -3);

  floydWarshall(g);

  cout << "Distances between nodes" << endl;
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      cout.precision(4);
      cout << d[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Predecessors" << endl;
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      cout.precision(4);
      cout << p[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
