/*
 * Chapter 19
 * Paragraph 2
 *
 */

#ifndef MFSET_H
#define MFSET_H

class Mfset {
public:
  Mfset(int n);

  int find(int x);

  void merge(int x, int y);

  ~Mfset();

private:
  int* p;
  int* rango;
};

#endif
