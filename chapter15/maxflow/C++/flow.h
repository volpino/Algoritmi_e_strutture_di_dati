/*
 * Chapter 15
 * Paragraph 2
 */

#ifndef FLOW_H
#define FLOW_H

#include "../../../chapter09/graphs/C++/graph.h"
#include <climits>
#include <algorithm>

//search augmenting path with depth first search
template <class T>
int dfs(Graph<T>& G,
        int **r, //residual capacity
        int i,   //current node
        int p,   //sink
        bool* visited,
        int min,
        int **g) //output augmenting flow
{
  //if sink has been reached, terminate
  if (i==p)
  {
    return min;
  }

  visited[i] = true;
  for (int j=0; j < G.num_vertex; j++)
  {
    if (r[i][j] > 0 && !visited[j])
    {
      // For each adjacent node j that has not been visited...

      // Recursively perform the DFS, using the capacity of edge [i,j]
      //if smaller than the min found so far.
      int v = dfs(G, r, j, p, visited, std::min(min, r[i][j]), g);

      // If v>0, we have found the sink, and v is the maximu value of the flow
      //along the path connecting the source and sink.
      if (v > 0)
      {
        r[i][j] = r[i][j]-v;
        g[i][j] = g[i][j]+v;
        r[j][i] = r[j][i]+v;
        g[j][i] = g[j][i]-v;
        return v;
      }
    }
  }
  // The sink has not been found.
  return 0;
}

//returns true if an augmenting path is found
template <class T>
bool augmenting_flow(Graph<T>& G,
                     int **r, //residual capacity
                     int s,   //source
                     int p,   //sink
                     int **g) //output augmenting flow
{
  bool* visited = new bool[G.num_vertex];
  for (int i=0; i<G.num_vertex; i++)
    visited[i] = false;
  //initial flow is zero
  for (typename Graph<T>::iterator i=G.v()->begin(); i!=G.v()->end(); i++)
  {
    for (typename Graph<T>::iterator j=G.v()->begin(); j!=G.v()->end(); j++)
    {
      int u = G.id(*i);
      int v = G.id(*j);
      g[u][v] = 0;
    }
  }
  int min = dfs(G, r, s, p, visited, INT_MAX, g);
  delete[] visited;
  return (min > 0);
}

template <class T>
void maxFlow(Graph<T>& G,
             int s, //source
             int p, //sink
             int** f) //flow matrix output
{
  //initialize matrix for augmenting path
  int **g = new int*[G.num_vertex];
  for (int i=0; i<G.num_vertex; i++)
    g[i] = new int[G.num_vertex];

  //initialize matrix for remaining flow net
  int **r = new int*[G.num_vertex];
  for (int i=0; i<G.num_vertex; i++)
    r[i] = new int[G.num_vertex];

  //initial flow is zero
  for (typename Graph<T>::iterator i=G.v()->begin(); i!=G.v()->end(); i++)
  {
    for (typename Graph<T>::iterator j=G.v()->begin(); j!=G.v()->end(); j++)
    {
      int u = G.id(*i);
      int v = G.id(*j);
      f[u][v] = 0;
    }
  }

  bool stop = false;
  while (!stop)
  {
    //compute remaining flow net in r
    for (typename Graph<T>::iterator i=G.v()->begin(); i!=G.v()->end(); i++)
    {
      for (typename Graph<T>::iterator j=G.v()->begin(); j!=G.v()->end(); j++)
      {
        int u = G.id(*i);
        int v = G.id(*j);
        r[u][v] = G.w(*i,*j) - f[u][v];
      }
    }

    //compute augmenting flow over r
    stop = !augmenting_flow(G, r, s, p, g);

    //update new flow
    for (typename Graph<T>::iterator i=G.v()->begin(); i!=G.v()->end(); i++)
    {
      for (typename Graph<T>::iterator j=G.v()->begin(); j!=G.v()->end(); j++)
      {
        int u = G.id(*i);
        int v = G.id(*j);
        f[u][v] += g[u][v];
      }
    }
  }

  //deallocate memory
  for (int i=0; i<G.num_vertex; i++)
    delete[] g[i];
  delete[] g;
  for (int i=0; i<G.num_vertex; i++)
    delete[] r[i];
  delete[] r;
}

#endif
