#ifndef RBTREE_H
#define RBTREE_H

#include <cstddef>
#include <cassert>

template <class Key, class T>
class RBTree {
public:
  enum Color {
    RED = 0,
    BLACK = 1,
  };

  RBTree(Key k, T v) : _key(k), _value(v), color(RED),
                       left(NULL), right(NULL), parent(NULL) { }

  RBTree<Key,T>* lookupNode(Key);

  void insertNode(Key, T);

  void removeNode(Key);

  void checkTree()
  {
    assert(this->color == BLACK);
    this->checkChildren();
    blackHeight();
  }

  void checkChildren()
  {
    if (this->color == RED)
    {
      if (this->left)
        assert(this->left->color == BLACK);
      if (this->right)
        assert(this->right->color == BLACK);
    }
    if (this->left)
      this->left->checkChildren();
    if (this->right)
      this->right->checkChildren();
  }

  int blackHeight()
  {
    int s = this->left ? this->left->blackHeight() : 0;
    int r = this->right ? this->right->blackHeight() : 0;
    assert(s==r);
    if (this->color == BLACK)
      s++;
    return s;
  }

private:
  void balanceInsert();

  void balanceDelete(RBTree*);

  void link(RBTree*, Key);

  void rotateLeft();

  void rotateRight();

  Key _key;
  T _value;
  Color color;
  RBTree* left;
  RBTree* right;
  RBTree* parent;
};

template <class Key, class T>
RBTree<Key,T>* RBTree<Key,T>::lookupNode(Key x)
{
  RBTree<Key,T>* t = this;
  while (t != NULL && t->_key != x) {
    t = (x < t->_key) ? t->left : t->right;
  }
  return t;
}

template <class Key, class T>
void RBTree<Key, T>::link(RBTree<Key, T>* u, Key x)
{
  RBTree<Key, T>* v = this;
  if (u != NULL)
  {
    u->parent = v;
  }
  if (v != NULL)
  {
    if (x < v->_key)
      v->left = u;
    else
      v->right = u;
  }
}

template <class Key, class T>
void RBTree<Key,T>::insertNode(Key x, T v)
{
  RBTree<Key, T>* s = NULL;
  RBTree<Key, T>* u = this;

  while (u != NULL && u->_key != x)
  {
    s = u;
    u = (x < u->_key) ? u->left : u->right;
  }
  if (u != NULL && u->_key == x)
  {
    u->_value = v;
  }
  else
  {
    RBTree<Key,T>* n = new RBTree<Key, T>(x, v);
    s->link(n, x);
    n->balanceInsert();
  }
}

template <class Key, class T>
void RBTree<Key,T>::removeNode(Key x)
{
  RBTree<Key,T>* u = this->lookupNode(x);
  if (u != NULL)
  {
    if (u->left != NULL && u->right != NULL)
    {
      RBTree<Key,T>* s = u->right;
      while (s->left != NULL)
      {
        s = s->left;
      }

      u->_key = s->_key;
      u->_value = s->_value;

      u = s;
    }

    RBTree<Key,T>* t;
    if (u->left != NULL && u->right == NULL)
    {
      t = u->left;
    }
    else
    {
      t = u->right;
    }
    if (u->parent == NULL)
    {
      // replace this with t
      this->_value = t->_value;
      this->_key = t->_key;
      this->parent = t->parent;
      this->left = t->left;
      this->right = t->right;
    }
    else
    {
      u->parent->link(t, x);
    }
    if (u->color == BLACK)
      this->balanceDelete(t);
    u->left = NULL;
    u->right = NULL;
    u->parent = NULL;
    delete u;
  }
}

template <class Key, class T>
void RBTree<Key,T>::balanceInsert()
{
  RBTree* t = this;
  while (t)
  {
    RBTree* p = t->parent;
    RBTree* n = p ? p->parent : NULL;
    RBTree* z = (n==NULL) ? NULL : ((n->left == p) ? n->right : n->left);
    if (p == NULL)  //case 1
    {
      t->color = BLACK;
      t = NULL;
    }
    else if (p->color == BLACK)
    {
      t = NULL;
    }
    else if (z->color == RED) //case 3
    {
      p->color = z->color = BLACK;
      n->color = RED;
      t = n;
    }
    else
    {
      if (t == p->right && p == n->left)
      {
        p->rotateLeft();
        t = p;
      }
      else if (t == p->left && p == n->left)
      {
        p->rotateRight();
        t = p;
      }
      else
      {
        if (t==p->left && p==n->left)
          n->rotateRight();
        else
          n->rotateLeft();
        p->color = BLACK;
        n->color = RED;
        t = NULL;
      }
    }
  }
}

template <class Key, class T>
void RBTree<Key,T>::balanceDelete(RBTree<Key, T>* t)
{
  while (t!=this && t->color == BLACK)
  {
    RBTree<Key,T>* p = t->parent;
    if (t == p->left)
    {
      RBTree<Key,T>* f = p->right;
      RBTree<Key,T>* ns = f->left;
      RBTree<Key,T>* nd = f->right;
      if (f->color == RED) //case 1
      {
        p->color = RED;
        f->color = BLACK;
        p->rotateLeft();
      }
      else
      {
        if (ns->color == nd->color && nd->color == BLACK) //case 2
        {
          f->color = RED;
          t = p;
        }
        else if (ns->color == RED && nd->color == BLACK) //case 3
        {
          ns->color = BLACK;
          f->color = RED;
          f->rotateRight();
        }
        else if (nd->color == RED) // case4
        {
          f->color = p->color;
          p->color = BLACK;
          nd->color = BLACK;
          p->rotateLeft();
          t = NULL;
        }
      }
    }
    else
    {
      RBTree<Key,T>* f = p->left;
      RBTree<Key,T>* ns = f->left;
      RBTree<Key,T>* nd = f->right;
      if (f->color == RED) //case 1
      {
        p->color = RED;
        f->color = BLACK;
        p->rotateRight();
      }
      else
      {
        if (ns->color == nd->color && nd->color == BLACK) //case 2
        {
          f->color = RED;
          t = p;
        }
        else if (ns->color == RED && nd->color == BLACK) //case 3
        {
          ns->color = BLACK;
          f->color = RED;
          f->rotateRight();
        }
        else if (nd->color == RED) // case4
        {
          f->color = p->color;
          p->color = BLACK;
          nd->color = BLACK;
          p->rotateRight();
          t = NULL;
        }
      }
    }
  }
  if (t != NULL)
    t->color = BLACK;
}

template<class Key, class T>
void RBTree<Key,T>::rotateLeft()
{
  RBTree<Key,T>* x = this;
  RBTree* y = this->right;
  RBTree* p = this->parent;
  this->right = y->left;
  if (y->left)
    y->left->parent = x;
  y->left = x;
  x->parent = y;
  if (p)
  {
    if (p->left == x)
      p->left = y;
    else
      p->right = y;
  }
}

template <class Key, class T>
void RBTree<Key,T>::rotateRight()
{
  RBTree<Key,T>* x = this;
  RBTree* y = this->left;
  RBTree* p = this->parent;
  this->left = y->right;
  if (y->right)
    y->right->parent = x;
  y->right = x;
  x->parent = y;
  if (p)
  {
    if (p->left == x)
      p->left = y;
    else
      p->right = y;
  }
}

#endif
