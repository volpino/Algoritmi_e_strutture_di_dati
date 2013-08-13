/*
 * Chapter 13
 * Paragraph 4
 */

public class StringMatching {
    final int DIM = 10000;
    private int D[] = new int[DIM];

    int match(String P, String T) {
        for (int j=0; j<=T.length(); j++) D[j] = 0;

        for (int i=1; i<=P.length(); i++) {
            int dx = i-1;
            for (int j=1; j<=T.length(); j++) {
                int t = Math.min(
                    Math.min(
                        dx + (P.charAt(i-1) == T.charAt(j-1) ? 0 : 1),
                        D[j] + 1
                    ),
                    D[j-1] + 1
                );

                dx = D[j];
                D[j] = t;
            }
            D[0] = i;
        }

        int minimo = D[0];
        for (int i=1; i<=T.length(); i++) minimo = Math.min(minimo, D[i]);

        return minimo;
    }


    public static void main(String[] args) {
        System.out.println("Result: " + new StringMatching().match("pippo", "voglio la pappa"));
    }
}
