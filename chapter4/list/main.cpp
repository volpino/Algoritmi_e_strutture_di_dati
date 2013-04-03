#include <iostream>

#include "list.h"

using namespace std;

int main()
{
  List<int> l;

  for (int i=0; i<11; i++)
  {
    l.insert_before(l.end(),i);
  }

  List<int>::iterator it = l.begin();
  while (!l.finished(it))
  {
    l.insert_before(it,15);
    l.write(it,20);
    it++;
  }

  for (it=l.begin(); it!=l.end(); it++)
  {
    cout << *it << endl;
  }
  cout << endl;
  for (it=--l.end(); !(it==l.begin()); it--)
  {
    cout << *it << endl;
  }
  cout << *it << endl;
  return 0;
}
