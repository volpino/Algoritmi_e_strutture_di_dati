/*
 * Chapter 13
 * Paragraph 4
 *
 * Fibonacci in O(1) space and O(n) time
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int fibonacci(int n) {
  int f0, f1, f2;
  f0 = f1 = f2 = 1;

  for (int i=2; i<n; i++) {
    f0 = f1;
    f1 = f2;
    f2 = f0 + f1;
  }

  return f2;
}


int main(int argc, char** argv) {
  if (argc <= 1) {
    cout << "Usage: " << argv[0] << " N" << endl;
    return 1;
  }

  cout << fibonacci(atoi(argv[1])) << endl;
  return 0;
}
