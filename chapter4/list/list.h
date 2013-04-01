/*
 * LICENSE
 */

#ifndef LIST_H
#define LIST_H

template <class T>
class List_iterator;

template <class T>
struct Node;

template <class T>
class List {
public:
  typedef List_iterator<T> iterator;

  List();
  ~List();

  bool empty();

  iterator begin();
  iterator end();

  bool finished(iterator);

  void write(iterator, T);

  void insert_before(iterator, T);

  void remove(iterator& p);

private:
  Node<T>* first_node;
};

#endif
