/*
 * Chapter 6
 * Paragraph 1
 *
 * Binary tree data structure implementation
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T>
class BinaryTree {
public:
  BinaryTree(T, T);

  BinaryTree* lookupNode(T);

  void link(BinaryTree*, T);

  void insertNode(T, T);

  void removeNode(T);

  BinaryTree* min();

  BinaryTree* max();

  BinaryTree* successorNode();

  BinaryTree* predecessorNode();

  ~BinaryTree();

  T key() {return _key;}
  T value() {return _value;}

private:
  T _value;
  T _key;
  BinaryTree* parent;
  BinaryTree* left;
  BinaryTree* right;
};

template <class T>
BinaryTree<T>::BinaryTree(T k, T v) : _key(k), _value(v), parent(0), left(0), right(0) { }

template <class T>
BinaryTree<T>* BinaryTree<T>::lookupNode(T x)
{
  BinaryTree<T>* t = this;
  while (t != 0 && t->key() != x) {
    t = x < t->key() ? t->left : t->right;
  }
  return t;
}

template <class T>
void BinaryTree<T>::link(BinaryTree<T>* u, T x)
{
  BinaryTree<T>* v = this;
  if (u != 0) {
    u->parent = v;
  }
  if (v != 0) {
    if (x < v->key()) {
      v->left = u;
    }
    else {
      v->right = u;
    }
  }
}

template <class T>
void BinaryTree<T>::insertNode(T x, T v)
{
  BinaryTree<T>* s = 0;
  BinaryTree<T>* u = this;

  while (u != 0 && u->key() != x) {
    s = u;
    u = x < u->key() ? u->left : u->right;
  }
  if (u != 0 && u->key() == x) {
    u->_value = v;
  }
  else {
    BinaryTree<T>* n = new BinaryTree<T>(x, v);
    s->link(n, x);
  }
}


template <class T>
void BinaryTree<T>::removeNode(T x)
{
  BinaryTree<T>* u = this->lookupNode(x);
  if (u != 0) {
    if (u->left != 0 && u->right != 0) {
      BinaryTree<T>* s = u->right;
      while (s->left != 0) {
        s = s->left;
      }

      u->_key = s->key();
      u->_value = s->value();

      u = s;
    }

    BinaryTree<T>* t;
    if (u->left != 0 && u->right == 0) {
      t = u->left;
    }
    else {
      t = u->right;
    }
    if (u->parent == 0) {
      // replace this with t
      this->_value = t->_value;
      this->_key = t->_key;
      this->parent = t->parent;
      this->left = t->left;
      this->right = t->right;
    }
    else {
      u->parent->link(t, x);
    }
    u->left = 0;
    u->right = 0;
    u->parent = 0;
    delete u;
  }
}

template <class T>
BinaryTree<T>* BinaryTree<T>::min()
{
  BinaryTree<T>* t = this;
  while (t->left != 0) {
    t = t->left;
  }
  return t;
}

template <class T>
BinaryTree<T>* BinaryTree<T>::max()
{
  BinaryTree<T>* t = this;
  while (t->right != 0) {
    t = t->right;
  }
  return t;
}

template <class T>
BinaryTree<T>* BinaryTree<T>::successorNode()
{
  BinaryTree<T>* t = this;
  if (t == 0) {
    return t;
  }
  if (t->right != 0) {
    return t->right->min();
  }
  BinaryTree<T>* s = t->parent;
  while (s != 0 && t == s->right) {
    t = s;
    s = s->parent;
  }
  return s;
}


template <class T>
BinaryTree<T>* BinaryTree<T>::predecessorNode()
{
  BinaryTree<T>* t = this;
  if (t == 0) {
    return t;
  }
  if (t->left != 0) {
    return t->left->max();
  }
  BinaryTree<T>* s = t->parent;
  while (s != 0 && t == s->left) {
    t = s;
    s = s->parent;
  }
  return s;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
  BinaryTree<T>* u = this->successorNode();
  while (u)
  {
    BinaryTree<T>* next = u->successorNode();
    delete u;
    u = next;
  }
}


#endif
