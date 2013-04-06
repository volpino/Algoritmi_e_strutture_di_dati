/*
 * Chapter 5
 * Paragraph 4
 *
 * Tree data structure implementation (pointers to parent, child and sibling)
 */

#ifndef TREE_H
#define TREE_H

template <class T>
class Tree {
public:
  Tree(T);

  //inserts t before the first child
  void insertChild(Tree&);

  //inserts t before the current sibling
  void insertSibling(Tree&);

  void deleteChild();

  void deleteSibling();

  ~Tree();

  T value() {return _value;}

  Tree* rightSibling() { return sibling;}
  Tree* leftmostChild() { return child;}

private:
  T _value;
  Tree* parent;
  Tree* child;
  Tree* sibling;
};

template <class T>
Tree<T>::Tree(T v) : _value(v), parent(0), child(0), sibling(0) { }

template <class T>
void Tree<T>::insertChild(Tree& t)
{
  t.parent = this;
  t.sibling = child;
  child = &t;
}

template <class T>
void Tree<T>::insertSibling(Tree& t)
{
  t.parent = parent;
  t.sibling = sibling;
  sibling = &t;
}

template <class T>
void Tree<T>::deleteChild()
{
  if (child)
  {
    Tree* newChild = child->sibling;
    delete(child);
    child = newChild;
  }
}

template <class T>
void Tree<T>::deleteSibling()
{
  if (sibling)
  {
    Tree* newBrother = sibling->sibling;
    delete(sibling);
    sibling = newBrother;
  }
}

template <class T>
Tree<T>::~Tree()
{
  Tree* u = child;
  while (u)
  {
    Tree* next = u->sibling;
    delete u;
    u = next;
  }
}

#endif
