/*
 * Chapter 5
 * Paragraph 4
 *
 * Tree structure (with parents vector) definition
 */

#include "tree.h"

Tree::Tree(int n)
{
  //allocates space for n elements (from 1 to n)
  p = new int[n+1];
  for (int i=1; i<=n; i++)
    p[i] = 0;
}

//returns the parent node of i; returns 0 if i is the root
int Tree::parent(int i)
{
  return p[i];
}

//makes i child of j
void Tree::setParent(int i, int j)
{
  p[i] = j;
}

Tree::~Tree()
{
  delete[] p;
}

