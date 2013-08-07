#ifndef HEAPSORT_H
#define HEAPSORT_H

/*
 * Chapter 10
 * Paragraph 1.4
 *
 * Heap priority queue data structure
 */
using namespace std;


template <class T>
class HeapSort {
public:
  HeapSort(T* array, int n) {
    this->array = array;
    this->n = n;
  };

  void heapBuild() {
    for (int i=n/2; i>=0; i--) {
      maxHeapRestore(i);
    }
  };

  void maxHeapRestore(int i) {
    int max = i;
    if (left(i) < n && array[left(i)] > array[max]) {
      max = left(i);
    }

    if (right(i) < n && array[right(i)] > array[max]) {
      max = right(i);
    }

    if (i != max) {
      swap(i, max);
      maxHeapRestore(max);
    }
  };

  void heapSort() {
    heapBuild();
    for (int i=n-1; i>=0; i--) {
      swap(0, i);
      n--;
      maxHeapRestore(0);
    }
  };

  ~HeapSort() {
  };

private:
  T* array;
  int n;

  void swap(int i, int j) {
    T tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
  };

  int parent(int i) {
    return i / 2;  // integer division
  };

  int left(int i) {
    return 2 * i;
  };

  int right(int i) {
    return (2 * i) + 1;
  };
};

# endif
