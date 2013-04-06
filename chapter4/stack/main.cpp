/*
 * Chapter 4
 * Paragraph 3
 *
 * Stack data structure usage
 */

#include <iostream>
#include "stack.h"

using namespace std;

const int dim=20;

int main()
{
  Stack<int> s(dim);

  for (int i=0; i<10; i++)
  {
    s.push(i);
  }

  while(!s.isEmpty())
  {
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}
