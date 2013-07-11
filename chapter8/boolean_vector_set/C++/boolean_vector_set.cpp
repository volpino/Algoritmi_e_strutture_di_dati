/*
 * Chapter 8
 * Paragraph 1
 *
 * Boolean vector set data structure
 */

#include<iostream>
#include<algorithm>
using namespace std;

class BooleanSet {
public:
  BooleanSet(int n) : dim(0), tot(n), v(0)
  {
    dim = 0;
    v = new bool[tot];
    for (int i=0; i<tot; i++) {
      v[i] = false;
    }
  };

  int size() {return dim; };

  bool contains(int x) {
    if (x >= tot) {
      return false;
    }
    return v[x];
  };

  void insert(int x) {
    if (x >= tot) {
      return;
    }
    if (!v[x]) {
      dim++;
    }
    v[x] = true;
  };

  void remove(int x) {
    if (x >= tot) {
      return;
    }

    if (v[x]) {
      dim--;
    }
    v[x] = false;
  };

  void unione(BooleanSet& other) {
    int new_tot = max(this->tot, other.tot);
    int new_dim = 0;
    bool* new_v = new bool[new_tot];
    for (int i=0; i<new_tot; i++) {
      if (this->contains(i) || other.contains(i)) {
        new_v[i] = true;
        new_dim++;
      }
      else {
        new_v[i] = false;
      }
    }
    delete[] this->v;
    this->v = new_v;
    this->tot = new_tot;
    this->dim = new_dim;
  }

  void intersection(BooleanSet& other) {
    int new_dim = 0;
    bool* new_v = new bool[this->tot];
    for (int i=0; i<this->tot; i++) {
      if (this->contains(i) && other.contains(i)) {
        new_v[i] = true;
        new_dim++;
      }
      else {
        new_v[i] = false;
      }
    }
    delete[] this->v;
    this->v = new_v;
    this->dim = new_dim;
  }

  void difference(BooleanSet& other) {
    int new_dim = 0;
    bool* new_v = new bool[this->tot];
    for (int i=0; i<this->tot; i++) {
      if (this->contains(i) && !other.contains(i)) {
        new_v[i] = true;
        new_dim++;
      }
      else {
        new_v[i] = false;
      }
    }
    delete[] this->v;
    this->v = new_v;
    this->dim = new_dim;
  }

  ~BooleanSet() {
    delete[] v;
  }

private:
  bool* v;
  int dim;
  int tot;
};


int main() {
  BooleanSet* s = new BooleanSet(10);
  s->insert(3);
  s->insert(6);
  cout << "Set s size: " << s->size() << endl;

  BooleanSet* t = new BooleanSet(100);
  t->insert(42);
  t->insert(21);
  t->insert(91);
  cout << "Set t size: " << t->size() << endl;

  s->unione(*t);

  cout << "Set s size: " << s->size() << endl;
  cout << "Set s contains 42 and 6? " << (s->contains(42) && s->contains(6) ? "Yes" : "No") << endl;
}
