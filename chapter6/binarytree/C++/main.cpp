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
  BinaryTree<int>* t = new BinaryTree<int>(1, 10);
  t->insertNode(2, 42);
  t->insertNode(99, 99);
  t->insertNode(2, 20);
  t->insertNode(0, 1);
  t->insertNode(5, 50);
  t->insertNode(3, 30);
  t->insertNode(4, 40);
  t->insertNode(0, 42);

  cout << "Il nodo minimo è " << t->min()->key() << "=" << t->min()->value() << endl;
  cout << "Il nodo massimo è " << t->max()->key() << "=" << t->max()->value() << endl;

  cout << "Rimuovo nodo 0" << endl;
  t->removeNode(0);

  cout << "Il nodo minimo è " << t->min()->key() << "=" << t->min()->value() << endl;
  cout << endl;
  cout << "Ora stampo i nodi dell'albero in ordine: " << endl;
  BinaryTree<int>* s = t;
  while(s) {
    cout << "Nodo: " << s->key() << "=" << s->value() << endl;
    s = s->successorNode();
  }

  cout << endl;
  cout << "Ora stampo i nodi dell'albero in ordine inverso: " << endl;
  s = t->lookupNode(99);
  while(s) {
    cout << "Nodo: " << s->key() << "=" << s->value() << endl;
    s = s->predecessorNode();
  }

  delete t;
}
