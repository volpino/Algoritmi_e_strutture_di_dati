/*
 * Chapter 7
 * Paragraph 2
 *
 * Simple hash implementation
 */

#include "hash.h"
#include <iostream>
using namespace std;

int main() {
  Hash<int> myhash(15);
  myhash.insert(string("90's plaid"), 3);
  myhash.insert(string("hipster ipsum"), 1);
  myhash.remove(string("90's plaid"));
  myhash.insert(string("Wes Anderson "), 2);
  myhash.insert(string("lomo"), 4);
  myhash.insert(string("McSweeney's Tonx hashtag twee"), 5);
  myhash.insert(string("vegan craft beer"), 6);
  myhash.insert(string("90's plaid"), 3);

  cout << myhash.lookup(string("non esisto")) << endl;
  cout << *myhash.lookup(string("hipster ipsum")) << endl;
  cout << *myhash.lookup(string("Wes Anderson ")) << endl;
  cout << *myhash.lookup(string("90's plaid")) << endl;
  cout << *myhash.lookup(string("lomo")) << endl;
  cout << *myhash.lookup(string("McSweeney's Tonx hashtag twee")) << endl;
  cout << *myhash.lookup(string("vegan craft beer")) << endl;
}
