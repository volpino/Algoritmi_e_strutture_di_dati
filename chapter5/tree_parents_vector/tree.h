/*
 *
 */

#ifndef TREE_H
#define TREE_H

class Tree {
public:
  Tree(int);

  //returns the parent node of i; returns 0 if i is a root
  int parent(int i);

  //makes i child of j
  void setParent(int i, int j);

  ~Tree();

private:
  int* p; //parents vector
};

#endif
