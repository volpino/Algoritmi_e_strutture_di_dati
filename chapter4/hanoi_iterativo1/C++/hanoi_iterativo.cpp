/*
 * Chapter 4
 * Paragraph 4
 *
 * Hanoi-iterativa
 */

#include <iostream>
#include <stack>
using namespace std;

void hanoi_iterativa(int n, int origine, int destinazione, int intermedio) {
  int temp;
  int* array;
  stack<int*> s;
  bool finedelmondo = false;
  while (!finedelmondo) {
    while (n != 1) {
      array = new int[4];
      array[0] = n;
      array[1] = origine;
      array[2] = destinazione;
      array[3] = intermedio;
      s.push(array);
      n--;

      temp = destinazione;
      destinazione = intermedio;
      intermedio = temp;
    }
    cout << "Trasferisci un disco da " << origine << " a " << destinazione << endl;
    if (s.empty()) {
      finedelmondo = true;
    }
    else {
      array = s.top();
      s.pop();
      n = array[0];
      origine = array[1];
      destinazione = array[2];
      intermedio = array[3];
      delete array;
      cout << "Trasferisci un disco da " << origine << " a " << destinazione << endl;
      n = n - 1;
      temp = origine;
      origine = intermedio;
      intermedio = temp;
    }
  }
}

int main()
{
  hanoi_iterativa(3, 1, 3, 2);
  return 0;
}
