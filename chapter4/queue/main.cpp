/*
 * Chapter 4
 * Paragraph 3
 *
 * Queue data structure usage
 */

#include <iostream>
#include "queue.h"

using namespace std;

const int dim=20;

int main()
{
  Queue<int> q(dim);

  for (int i=0; i<10; i++)
  {
    q.enqueue(i);
  }

  while(!q.isEmpty())
  {
    cout << q.top() << endl;
    q.dequeue();
  }

  return 0;
}
