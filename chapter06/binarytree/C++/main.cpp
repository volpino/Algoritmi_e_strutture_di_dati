/*
 * Chapter 6
 * Paragraph 1
 *
 * Binary tree data structure usage
 */

#include "binarytree.h"
#include <iostream>

using namespace std;

int main() {
  BinaryTree<int>* t = new BinaryTree<int>(4, 40);
  t->insertNode(2, 42);
  t->insertNode(5, 50);
  t->insertNode(2, 20);
  t->insertNode(0, 1);
  t->insertNode(99, 99);
  t->insertNode(3, 30);
  t->insertNode(1, 10);
  t->insertNode(0, 42);
  t->insertNode(-1, 10);

  cout << "Rimuovo nodi 0 e 4" << endl;
  t = t->removeNode(0);
  t = t->removeNode(4);

  cout << "Ora stampo i nodi dell'albero in ordine: " << endl;
  BinaryTree<int>* s = t->min();
  while(s) {
    cout << "Nodo: " << s->key() << "=" << s->value() << endl;
    s = s->successorNode();
  }

  cout << endl;
  cout << "Ora stampo i nodi dell'albero in ordine inverso: " << endl;
  s = t->max();
  while(s) {
    cout << "Nodo: " << s->key() << "=" << s->value() << endl;
    s = s->predecessorNode();
  }

  delete t;
}
