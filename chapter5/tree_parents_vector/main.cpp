#include "tree.h"

#include <iostream>

using namespace std;

char a[11] = {'*','a','b','c','d','e','f','g','h','i','j'};

void path_to_root(int i, Tree& t)
{
  if (i>0)
  {
    cout << a[i] << endl;
    path_to_root(t.parent(i),t);
  }
}

int main()
{
  Tree t(10);

  t.setParent(2,1);
  t.setParent(3,1);
  t.setParent(4,2);
  t.setParent(5,2);
  t.setParent(6,3);
  t.setParent(7,3);
  t.setParent(8,4);
  t.setParent(9,4);
  t.setParent(10,5);
  path_to_root(10,t);
  cout << endl;
  path_to_root(4,t);
}
