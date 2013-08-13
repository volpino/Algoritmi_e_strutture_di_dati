/*
 * Chapter 14
 * Paragraph 3.1
 *
 * Kruskal minimum spanning tree algorithm
 */

#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
#include "../../../chapter10/mfset/C++/mfset.h"

using namespace std;

struct edge {
  int u;
  int v;
  int weight;
};


bool operator < (const edge a, const edge b) {
  return a.weight < b.weight;
}


void kruskal(vector<edge> A, int n, int m, set<edge> &T) {
  Mfset mf(n);

  sort(A.begin(), A.end());

  int c = 0;
  int i = 0;

  while (c < n-1 && i<=m) {
    if (mf.find(A[i].u) != mf.find(A[i].v)) {
      mf.merge(A[i].u, A[i].v);
      T.insert(A[i]);
      c++;
    }
    i++;
  }
}


int main() {
  edge tmp;
  vector<edge> edges;

  tmp.u = 1; tmp.v = 2; tmp.weight = 9; edges.push_back(tmp);
  tmp.u = 1; tmp.v = 3; tmp.weight = 6; edges.push_back(tmp);

  tmp.u = 2; tmp.v = 3; tmp.weight = 11; edges.push_back(tmp);
  tmp.u = 2; tmp.v = 4; tmp.weight = 1; edges.push_back(tmp);
  tmp.u = 2; tmp.v = 5; tmp.weight = 20; edges.push_back(tmp);

  tmp.u = 3; tmp.v = 4; tmp.weight = 2; edges.push_back(tmp);
  tmp.u = 3; tmp.v = 6; tmp.weight = 18; edges.push_back(tmp);

  tmp.u = 4; tmp.v = 5; tmp.weight = 13; edges.push_back(tmp);
  tmp.u = 4; tmp.v = 6; tmp.weight = 28; edges.push_back(tmp);
  tmp.u = 4; tmp.v = 7; tmp.weight = 15; edges.push_back(tmp);

  tmp.u = 5; tmp.v = 7; tmp.weight = 3; edges.push_back(tmp);

  tmp.u = 6; tmp.v = 7; tmp.weight = 25; edges.push_back(tmp);

  set<edge> result;
  kruskal(edges, 7, edges.size(), result);

  for (set<edge>::iterator it=result.begin(); it!=result.end(); it++) {
    cout << (*it).u << " - " << (*it).v << endl;
  }
}
