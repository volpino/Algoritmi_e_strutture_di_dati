#include "list.h"

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
  Node<T>* n = new Node<T>();
  n->pred = n;
  n->succ = n;
  first_node = n;
}
/*
template <class T>
List<T>::List(const List<T>& li)
{
  for (iterator it=li.begin(); it!=li.end(); it++)
  {
    insert_before(end(),*it);
  }
  }*/

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
  iterator it = begin();
  while (!empty())
  {
    remove(it);
  }
}

/*
template <class T>
List<T>& List<T>::operator=(const List& li)
{
  if (&li != this)
  {
    while (!empty())
    {
      remove(begin());
    }
    for (iterator it=li.begin(); it!=li.end(); it++)
    {
      insert_before(end(),*it);
    }
  }
  return *this;
  }*/

template class List<int>;

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

template class List_iterator<int>;
