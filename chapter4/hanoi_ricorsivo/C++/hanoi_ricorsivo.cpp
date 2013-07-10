/*
 * Chapter 4
 * Paragraph 4
 *
 * Hanoi-ricorsiva
 */

#include <iostream>
using namespace std;

void hanoi_ricorsiva(int n, int origine, int destinazione, int intermedio) {
  if (n == 1) {
    cout << "Trasferisci un disco da " << origine << " a " << destinazione << endl;
  }
  else {
    hanoi_ricorsiva(n-1, origine, intermedio, destinazione);
    cout << "Trasferisci un disco da " << origine << " a " << destinazione << endl;
    hanoi_ricorsiva(n-1, intermedio, destinazione, origine);
  }
}

int main()
{
  hanoi_ricorsiva(3, 1, 3, 2);
  return 0;
}
