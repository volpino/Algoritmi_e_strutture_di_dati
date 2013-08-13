/*
 * Chapter 13
 * Paragraph 4
 *
 * Fibonacci in O(1) space and O(n) time
 */

public class Fibonacci {
    public static int compute(int n) {
        int f0, f1, f2;
        f0 = f1 = f2 = 1;

        for (int i=2; i<n; i++) {
            f0 = f1;
            f1 = f2;
            f2 = f0 + f1;
        }

        return f2;
    }

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Usage: java Fibonacci N");
        }
        else {
            System.out.println(Fibonacci.compute(Integer.parseInt(args[0])));
        }
    }
}
