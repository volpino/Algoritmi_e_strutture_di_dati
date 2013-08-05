/*
 * Chapter 6
 * Paragraph 1
 *
 * Binary tree data structure usage
 */

#include "rbtree.h"
#include <iostream>

using namespace std;

int main() {
  RBTree<int,int>* t = new RBTree<int,int>(1, 10);
  t->insertNode(2, 42);
  t->insertNode(99, 99);
  t->insertNode(2, 20);
  t->insertNode(0, 1);
  t->insertNode(5, 50);
  t->insertNode(3, 30);
  t->insertNode(4, 40);
  t->insertNode(0, 42);

  t->checkTree();

  cout << "Rimuovo nodo 0" << endl;
  t->removeNode(0);

  t->checkTree();
}
