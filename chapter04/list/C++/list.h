/*
 * Chapter 4
 * Paragraph 1
 *
 * List data structure implementation
 */

#ifndef LIST_H
#define LIST_H

template <class T>
class List_iterator;

template <class T>
struct Node;

////////////// LIST CLASS DECLARATION //////////////

template <class T>
class List {
public:
  typedef List_iterator<T> iterator;

  List();
  List(const List&);
  ~List();

  bool empty();

  iterator begin();
  iterator end();

  bool finished(iterator);

  void write(iterator, T);

  void insert_before(iterator, T);

  void remove(iterator& p);

  List& operator=(const List&);

private:
  Node<T>* first_node;
};

////////////// LIST ITERATOR CLASS DECLARATION //////////////

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

template <class T>
struct Node
{
  Node* pred;
  Node* succ;
  T value;
};

////////////// LIST CLASS DEFINITION //////////////

template <class T>
List<T>::List()
{
  //initialize sentinel
  first_node = new Node<T>();
  first_node->pred = first_node;
  first_node->succ = first_node;
}

template <class T>
List<T>::List(const List<T>& li)
{
  //initialize sentinel
  first_node = new Node<T>();
  first_node->pred = first_node;
  first_node->pred = first_node;
  //copy values from li
  for (Node<T>* n=li.first_node->succ; n!=li.first_node; n=n->succ)
  {
    insert_before(end(),n->value);
  }
}

template <class T>
bool List<T>::empty()
{
  return ((this->first_node->pred == this->first_node->succ) &&
          (this->first_node->succ == this->first_node));
}

template <class T>
List_iterator<T> List<T>::begin()
{
  return List_iterator<T>(first_node->succ);
}

template <class T>
List_iterator<T> List<T>::end()
{
  //return first invalid value (so that it allows looping using != condition)
  return List_iterator<T>(first_node);
}

template <class T>
bool List<T>::finished(iterator p)
{
  return (p.node == first_node);
}

template <class T>
void List<T>::write(iterator p, T v)
{
  p.node->value = v;
}

template <class T>
void List<T>::insert_before(iterator p, T v)
{
  Node<T>* t = new Node<T>();
  t->value = v;
  t->pred = p.node->pred;
  t->pred->succ = t;
  t->succ = p.node;
  p.node->pred = t;
}

//the iterator is passed by reference because after the deletion it is moved
//to the next element
template <class T>
void List<T>::remove(iterator& p)
{
  Node<T>* t;
  p.node->pred->succ = p.node->succ;
  p.node->succ->pred = p.node->pred;
  t = p.node;
  p++;
  delete t;
}


template <class T>
List <T>::~List()
{
  //remove all elements
  iterator it = begin();
  while (!empty())
  {
    remove(it);
  }
  //deallocate sentinel
  delete first_node;
}


template <class T>
List<T>& List<T>::operator=(const List& li)
{
  if (&li != this)
  {
    //delete pre-existing values
    iterator it = begin();
    while (!empty())
    {
      remove(it);
    }
    //insert new values from li
    for (Node<T>* n=li.first_node->succ; n!=li.first_node; n=n->succ)
    {
      insert_before(end(),n->value);
    }
  }
  return *this;
}

////////////// LIST_ITERATOR CLASS DEFINITION //////////////

template <class T>
T& List_iterator<T>::operator*()
{
  return node->value;
}

template <class T>
List_iterator<T>& List_iterator<T>::operator++()
{
  node = node->succ;
  return *this;
}

template <class T>
List_iterator<T> List_iterator<T>::operator++(int)
{
  List_iterator orig = *this;
  ++(*this);
  return orig;
}

template <class T>
List_iterator<T>& List_iterator<T>::operator--()
{
  node = node->pred;
  return *this;
}

template <class T>
List_iterator<T> List_iterator<T>::operator--(int)
{
  List_iterator orig = *this;
  --(*this);
  return orig;
}

template<class T>
bool List_iterator<T>::operator==(const iterator& lit) const
{
    return (this->node == lit.node);
}

template <class T>
bool List_iterator<T>::operator!=(const iterator& lit) const
{
    return !(this->node == lit.node);
}

#endif
