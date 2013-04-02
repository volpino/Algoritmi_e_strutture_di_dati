#include <iostream>

#include "list.h"

using namespace std;

int main()
{
  List<int> l, l1;

  for (int i=0; i<11; i++)
  {
    l.insert_before(l.end(),i);
  }
  cout << "input" << endl;
  for (List<int>::iterator it=l.begin(); it!=l.end(); it++)
  {
    cout << *it << endl;
  }
}
