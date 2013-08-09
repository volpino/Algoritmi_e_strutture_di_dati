/*
 * Chapter 19
 * Paragraph 2
 *
 */

#include "mfset.h"

Mfset::Mfset(int n)
{
  this->p = new int[n+1];
  this->rango = new int[n+1];
  for (int i=0; i<=n; i++)
  {
    this->p[i] = i;
    this->rango[i] = 0;
  }
}

int Mfset::find(int x)
{
  if (p[x] != x)
    p[x] = this->find(p[x]);
  return p[x];
}

void Mfset::merge(int x, int y)
{
  int r_x = this->find(x);
  int r_y = this->find(y);
  if (r_x != r_y)
  {
    if (rango[r_x] > rango[r_y])
      p[r_y] = r_x;
    else if (rango[r_y] > rango[r_x])
      p[r_x] = r_y;
    else
    {
      p[r_x] = r_y;
      rango[r_y] = rango[r_y] + 1;
    }
  }
}

Mfset::~Mfset()
{
  delete[] this->p;
  delete[] this->rango;
}
