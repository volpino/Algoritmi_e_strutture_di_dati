/*
 * Chapter 7
 * Paragraph 2
 *
 * Simple hash implementation
 */

#ifndef HASH_H
#define HASH_H

#include <set>
#include <string>
#include <cmath>

using namespace std;

template <class T>
class Hash {
public:
  Hash(int capacita) {
    m = capacita;
    A = new string[m];
    V = new T[m];

    for (int i=0; i<m; i++) {
      empty.insert(i);
    }
  };

  int scan(string k, bool insert) {
    int c = m;
    int i = 0;
    int j = H(k);
    while (empty.find(j) == empty.end() && A[j].compare(k) != 0 && i < m) {
      if (deleted.find(j) != deleted.end() && c == m) {
        c = j;
      }
      j = (j + H1(k)) % m;
      i++;
    }
    return j;
  };

  T* lookup(string k) {
    int i = scan(k, false);
    if (A[i].compare(k) == 0) {
      return &V[i];
    }
    return 0;
  };

  bool insert(string k, T v) {
    int i = scan(k, true);
    if (empty.find(i) != empty.end() || deleted.find(i) != deleted.end() || A[i].compare(k) == 0) {
      A[i] = k;
      V[i] = v;
      empty.erase(i);
      deleted.erase(i);
      return true;
    }
    else {
      return false;
    }
  };

  void remove(string k) {
    int i = scan(k, false);
    if (deleted.find(i) == deleted.end() && empty.find(i) == empty.end() && A[i].compare(k) == 0) {
      deleted.insert(i);
    }
  };

  ~Hash() {
    delete[] A;
    delete[] V;
  };

private:
  string* A;
  T* V;
  int m;

  set<int> empty;
  set<int> deleted;

  int H(string k) {
    long double C = 0.6180339887498949;
    long double b = k[0] * C;
    for (int j=1; j<k.size(); j++) {
      b = fmod(((b * 256) + (k[j])) * C, 1);
    }
    return (((long double) m) * b);
  };

  int H1(string k) {
    int b = k[0];
    for (int j=1; j<k.size(); j++) {
      b = ((b * 256) + (k[j])) % m;
    }
    return b;
  };
};

#endif
