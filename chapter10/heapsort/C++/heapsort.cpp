#include "heapsort.h"
#include <iostream>

using namespace std;


int main() {
  int array[] = {4, 8, 23, 1, 5, 9, 12, 0};
  HeapSort<int> h = HeapSort<int>(array, 8);
  h.heapSort();

  for (int i=0; i<8; i++) {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}
