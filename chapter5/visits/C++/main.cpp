#include "visits.h"
#include <iostream>

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
}

int main()
{
  Tree<int> t(0);
  build_tree(t);

  visitaProfondita<int>(t);
  cout << endl;
  invisita<int>(t, 1);
  cout << endl;
  visitaAmpiezza<int>(t);
  return 0;
}
