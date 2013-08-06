#ifndef HEAP_H
#define HEAP_H

/*
 * Chapter 10
 * Paragraph 3
 *
 * Heap priority queue data structure
 */

#include <iostream>
using namespace std;

template <class T>
class HeapItem {
public:
  T value;
  int priority;
  int pos;

  HeapItem(T value, int priority, int pos) {
    this->value = value;
    this->priority = priority;
    this->pos = pos;
  };
};

template <class T>
class HeapQueue {
public:
  HeapQueue(int n) : used_slots(0), total(n), array(0)
  {
    array = new HeapItem<T>*[total];
  };

  int size() { return used_slots; };

  T min() {
    if (used_slots == 0) {
      return 0;
    }

    return array[0]->value;
  };

  bool insert(T value, int priority) {
    if (used_slots >= total) {
      return false;
    }

    array[used_slots] = new HeapItem<T>(value, priority, used_slots);

    int i = used_slots;
    while (i > 0 && array[i]->priority < array[parent(i)]->priority) {
      swap(i, parent(i));
      i = parent(i);
    }

    used_slots++;

    return true;
  };

  void minHeapRestore(int i) {
    int min = i;
    if (left(i) < used_slots && array[left(i)]->priority < array[min]->priority) {
      min = left(i);
    }

    if (right(i) < used_slots && array[right(i)]->priority < array[min]->priority) {
      min = right(i);
    }

    if (i != min) {
      swap(i, min);
      minHeapRestore(min);
    }
  };

  void deleteMin() {
    if (used_slots == 0) {
      return;
    }

    used_slots--;
    swap(0, used_slots);

    delete array[used_slots];  // deallocate HeapItem

    minHeapRestore(0);
  };

  ~HeapQueue() {
    for (int i=0; i<size(); i++) {
      deleteMin();
    }

    delete[] array;
  };

private:
  int used_slots;
  int total;
  HeapItem<T>** array;

  void swap(int i, int j) {
    HeapItem<T>* tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    array[i]->pos = i;
    array[j]->pos = j;
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
