/*
 * Chapter 6
 * Paragraph 1
 *
 * Binary tree data structure usage
 */

#include "rbtree.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  srand (time(NULL));
  RBTree<int,int>* t = new RBTree<int,int>(rand(), rand());

  for (int i=0; i<5; i++)
  {
    vector<int> nums;
    for (int i=0; i<10000; i++)
    {
      int temp = rand();
      //cout << "insert " << temp << endl;
      t = t->insertNode(temp,1);
      t->checkTree();
      nums.push_back(temp);
    }
    /*random_shuffle ( nums.begin(), nums.end() );
    for (vector<int>::iterator i=nums.begin(); i!=nums.end(); i++)
    {
      cout << "remove " << *i << endl;
      t = t->removeNode(*i);
      t->checkTree();
      }*/
  }
}
