/*
 * Chapter 5
 * Paragraph 2
 */

#ifndef VISITS_H
#define VISITS_H

#include "../../tree_pointers/C++/tree.h"
#include <iostream>
#include <queue>

using namespace std;

template<class T>
void visitaProfondita(Tree<T>& t)
{
  cout << t.value() << endl;
  Tree<T>* u = t.leftmostChild();
  while (u)
  {
    visitaProfondita<T>(*u);
    u = u->rightSibling();
  }
}

template<class T>
void invisita(Tree<T>& t, int i)
{
  Tree<T>* u = t.leftmostChild();
  int k = 0;
  while (u && k<i)
  {
    k++;
    invisita<T>(*u, i);
    u = u->rightSibling();
  }
  cout << t.value() << endl;
  while (u)
  {
    invisita<T>(*u, i);
    u = u->rightSibling();
  }
}

template<class T>
void visitaAmpiezza(Tree<T>& t)
{
  queue<Tree<T>*> q;
  q.push(&t);
  while (!q.empty())
  {
    Tree<T>* u = q.front();
    q.pop();
    cout << u->value() << endl;
    u = u->leftmostChild();
    while (u)
    {
      q.push(u);
      u = u->rightSibling();
    }
  }
}

#endif
