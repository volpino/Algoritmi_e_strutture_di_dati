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

  for (int i=0; i<10; i++)
  {
    vector<int> nums;
    for (int j=0; j<100000; j++)
    {
      int temp = rand();
      cout << "insert " << temp << endl;
      t = t->insertNode(temp,1);
      t->checkTree();
      nums.push_back(temp);
    }
    random_shuffle ( nums.begin(), nums.end() );
    for (vector<int>::iterator it=nums.begin(); it!=nums.end(); it++)
    {
      cout << "remove " << *it << endl;
      t = t->removeNode(*it);
      t->checkTree();
    }
  }
}
