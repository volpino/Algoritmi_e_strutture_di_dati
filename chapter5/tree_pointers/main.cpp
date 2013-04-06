/*
 * Chapter 5
 * Paragraph 4
 *
 * Tree data structure usage (pointers to parent, child and sibling)
 */

#include "tree.h"

using namespace std;

void build_tree(Tree<int>& t)
{
  if (t.value() < 3)
  {
    for (int i=0; i<3; i++)
    {
      Tree<int>* tmp = new Tree<int>(t.value()+1);
      build_tree(*tmp);
      t.insertChild(*tmp);
    }
  }
  t.deleteChild();
}

int main()
{
  Tree<int> t(0);
  build_tree(t);
  Tree<int>* tmp = &t;
  while ((tmp = tmp->leftmostChild()))
  {
    tmp->deleteSibling();
  }
  t.deleteChild();
}
