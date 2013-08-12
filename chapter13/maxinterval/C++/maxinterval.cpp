#include <set>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct int_val {
  int value;
  int type;
  int pos;
};

struct interval {
  int start;
  int end;
  int weight;
};

set<interval>* maxinterval(vector<interval> &intervals) {
  sort(intervals.begin(), intervals.end());

  vector<int_val> values;
  int* p = new int[intervals.size()];
  int* D = new int[intervals.size() + 1];

  for (int i=0; i<intervals.size(); i++) {
    int_val tmp;
    tmp.value = intervals[i].start;
    tmp.type = 0;
    tmp.pos = i;
    values.push_back(tmp);

    tmp.value = intervals[i].end;
    tmp.type = 1;
    tmp.pos = i;
    values.push_back(tmp);
  }

  sort(values.begin(), values.end());

  int i = -1;
  for (int j=0; j<values.size(); j++) {
    if (values[j].type == 0) {  // beginning of interval
      p[values[j].pos] = i;
    }
    else {  // end of interval
      i = values[j].pos;
    }
  }

  D[0] = 0;

  for (int i=0; i<intervals.size(); i++) {
    D[i+1] = max(D[i], intervals[i].weight + D[p[i] + 1]);
  }

  i = intervals.size() - 1;
  set<interval>* s = new set<interval>();

  while (i>=0) {
    if (D[i+1] > (intervals[i].weight + D[p[i] + 1])) {
      i--;
    }
    else {
      s->insert(intervals[i]);
      i = p[i];
    }
  }

  delete[] p;
  delete[] D;

  return s;
}


bool operator < (const interval &a , const interval &b) {
  if (a.end == b.end) {
    return a.start < b.start;
  }
  else {
    return a.end < b.end;
  }
}

bool operator < (const int_val a , const int_val b) {
  return a.value < b.value;
}


int main() {
  vector<interval> intervals;
  interval tmp;

  tmp.start = 1;
  tmp.end = 2;
  tmp.weight = 1;
  intervals.push_back(tmp);

  tmp.start = 1;
  tmp.end = 3;
  tmp.weight = 4;
  intervals.push_back(tmp);

  tmp.start = 2;
  tmp.end = 5;
  tmp.weight = 5;
  intervals.push_back(tmp);

  tmp.start = 3;
  tmp.end = 5;
  tmp.weight = 3;
  intervals.push_back(tmp);

  tmp.start = 5;
  tmp.end = 5;
  tmp.weight = 6;
  intervals.push_back(tmp);


  set<interval>* result = maxinterval(intervals);

  cout << "Result: " << result->size() << endl;
  for (set<interval>::iterator it=result->begin(); it != result->end(); it++) {
    cout << (*it).start << " - " << (*it).end << endl;
  }

  delete result;
}
