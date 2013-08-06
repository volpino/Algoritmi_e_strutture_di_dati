#include "heap.h"
#include <iostream>

using namespace std;


int main() {
  HeapQueue<int> h = HeapQueue<int>(10);

  h.insert(4, 4);
  h.insert(8, 8);
  h.insert(23, 23);
  h.insert(1, 1);
  h.insert(5, 5);
  h.insert(9, 9);
  h.insert(12, 12);
  h.insert(0, 0);
  cout << "Size: " << h.size() << endl;

  for (int i=h.size(); i>0; i--) {
    cout << h.min() << " ";
    h.deleteMin();
  }
  cout << endl;

  return 0;
}
