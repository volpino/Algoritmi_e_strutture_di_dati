/*
 * Chapter 17
 * Paragraph 2
 *
 * Test primality with Rabin algorithm
 */

import java.util.Scanner;


public class Prime {
    public static int pow_mod(int a, int x, int n) {
        int r = 1;

        while (x > 0) {  // process every bit of x
            if ((x & 1) == 1) {  // if the last bit of x is 1
                r = a*r % n;
            }

            a = a*a % n;
            x >>= 1;  // go on with the next bit
        }

        return r;
    }

    public static boolean is_prime(int n, int k) {
        // Write n-1 as m*2^v by factoring powers of 2 from n-1
        int v = 0;
        // count how many less significant bits of n-1 are set to 0
        for (int t=n-1; (t & 1) == 0; v++, t >>= 1 );
        int m = (n-1) / (1<<v);  // is the same as (n-1) / 2^v

        for (int j=0; j<k; j++) {
            int b = ((int) (Math.random() * (n-1))) + 1;
            int x = pow_mod(b, m, n);

            if (x == 1 || x == n-1) {
                continue;
            }

            boolean test_again = false;
            for (int r=1; r<v; r++) {
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

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Gimme a number: ");
        int x = in.nextInt();

        System.out.println(x + " is " + (is_prime(x, 100) ? "" : "not ") + "prime");
    }
}
