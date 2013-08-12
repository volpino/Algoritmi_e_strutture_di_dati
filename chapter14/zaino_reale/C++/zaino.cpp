#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct item {
  int profit;
  int volume;
  int pos;
};

void zaino(int p[], int v[], int c, int n, double x[]) {
  vector<item> items;
  for (int i=0; i<n; i++) {
    item x;
    x.profit = p[i];
    x.volume = v[i];
    x.pos = i;
    items.push_back(x);
  }

  sort(items.begin(), items.end());

  for (int i=0; i<n; i++) x[i] = 0;

  int i = 0;
  while (i<n && c>0) {
    if (items[i].volume >= c) {
      x[items[i].pos] = ((double) c) / items[i].volume;
      c = 0;
    }
    else {
      x[items[i].pos] = 1;
      c = c - items[i].volume;
    }
    i++;
  }
}

bool operator < (const item a , const item b) {
  return (((double) a.profit) / a.volume) > (((double) b.profit) / b.volume);
}


int main() {
  int p[] = {10, 99, 3, 21, 12, 64, 42, 64, 90, 10};
  int v[] = {30, 60, 2, 50, 15, 5, 10, 20, 25, 10};
  int n = 10;
  double x[10];
  int c = 50;

  zaino(p, v, c, n, x);

  cout << "Result: ";
  for (int i=0; i<n; i++) {
    cout << x[i] << " ";
  }
  cout << endl;
}
