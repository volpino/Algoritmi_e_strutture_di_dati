public class StringMatching {
    final int DIM = 10000;
    private int D[][] = new int[DIM][DIM];

    int match(String P, String T) {
        for (int i=1; i<=P.length(); i++) D[i][0] = i;
        for (int j=0; j<=T.length(); j++) D[0][j] = 0;

        for (int i=1; i<=P.length(); i++) {
            for (int j=1; j<=T.length(); j++) {
                int t = D[i-1][j-1] + (P.charAt(i-1) == T.charAt(j-1) ? 0 : 1);

                t = Math.min(t, D[i-1][j] + 1);
                t = Math.min(t, D[i][j-1] + 1);

                D[i][j] = t;
            }
        }

        int minimo = D[P.length()][0];
        int pos = 0;

        for (int j=1; j<=T.length(); j++) {
            if (D[P.length()][j] < minimo) {
                minimo = D[P.length()][j];
                pos = j;
            }
        }

        return pos;
    }


    public static void main(String[] args) {
        System.out.println("Result: " + new StringMatching().match("pippo", "quel lippo pippa di pippo ippo"));
    }
}
