#include "mfset.h"

#include <iostream>

using namespace std;

int main()
{
  Mfset mf(100);

  while (true)
  {
    int a,b;
    cout << "Merge?\n";
    cin >> a >> b;
    mf.merge(a,b);
    cout << "Find?\n";
    cin >> a;
    cout << "Rapr " << mf.find(a) << endl;
  }
  return 0;
}
