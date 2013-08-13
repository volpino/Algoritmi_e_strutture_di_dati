/*
 * Chapter 17
 * Paragraph 2
 *
 * Test primality with Rabin algorithm
 */

#include <iostream>
#include <cstdlib>

using namespace std;

typedef long long int lint;
typedef unsigned long long int ulint;


lint pow_mod(lint a, lint x, lint n) {
  lint r = 1;

  while (x > 0) {  // process every bit of x
    if ((x & 1) == 1) {  // if the last bit of x is 1
      r = a*r % n;
    }

    a = a*a % n;
    x >>= 1;  // go on with the next bit
  }

  return r;
}

bool is_prime(lint n, lint k) {
  // Write n-1 as m*2^v by factoring powers of 2 from n-1
  lint v = 0;
  // count how many less significant bits of n-1 are set to 0
  for (ulint t=n-1; (t & 1) == 0; v++, t >>= 1 );
  lint m = (n-1) / (1<<v);  // is the same as (n-1) / 2^v

  for (lint j=0; j<k; j++) {
    lint rnd = rand();
    lint b = rnd % (n-1) + 1;
    lint x = pow_mod(b, m, n);

    if (x == 1 || x == n-1) {
      continue;
    }

    bool test_again = false;
    for (lint r=1; r<v; r++) {
      x = pow_mod(x, 2, n);
      if (x == 1) {
        return false;
      }
      if (x == n-1) {
        test_again = true;
        break;
      }
    }
    if (!test_again) {
      return false;
    }
  }

  return true;
}


int main() {
  cout << "Gimme a number: ";
  lint x;
  cin >> x;

  cout << x << " is " << (is_prime(x, 100) ? "" : "not ") << "prime" << endl;
}
