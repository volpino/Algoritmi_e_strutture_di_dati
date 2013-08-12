#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

struct interval {
  int start;
  int end;
  int pos;
};

bool operator < (const interval a, const interval b) {
  return a.end < b.end;
}


void independent_set(int a[], int b[], int n, set<int> &output) {
  vector<interval> items;
  for (int i=0; i<n; i++) {
    interval tmp;
    tmp.start = a[i];
    tmp.end = b[i];
    tmp.pos = i;
    items.push_back(tmp);
  }

  sort(items.begin(), items.end());

  output.insert(items[0].pos);
  int ultimo = 0;

  for (int i=1; i<n; i++) {
    if (items[i].start >= items[ultimo].end) {
      output.insert(items[i].pos);
      ultimo = i;
    }
  }
}


int main() {
  int n = 5;
  int a[] = {0, 3, 2, 9, 0};
  int b[] = {1, 4, 5, 12, 10};

  set<int> output;

  independent_set(a, b, n, output);

  cout << "Result: ";
  for (set<int>::iterator it=output.begin(); it!=output.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}
