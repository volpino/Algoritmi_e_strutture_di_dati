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
  //List(const List&);
  ~List();

  bool empty();

  iterator begin();
  iterator end();

  bool finished(iterator);

  void write(iterator, T);

  void insert_before(iterator, T);

  void remove(iterator& p);

  //List& operator=(const List&);

private:
  Node<T>* first_node;
};


template <class T>
class List_iterator
{
public:
  typedef List_iterator<T> iterator;

  List_iterator(Node<T> *node): node(node) { }
  List_iterator(): node(0) { }

  T& operator*();
  bool operator==(const iterator & rhs) const;
  bool operator!=(const iterator & rhs) const;
  iterator& operator++();
  iterator operator++(int);
  iterator& operator--();
  iterator operator--(int);

private:
  Node<T> *node;

  friend class List<T>;
};

#endif
