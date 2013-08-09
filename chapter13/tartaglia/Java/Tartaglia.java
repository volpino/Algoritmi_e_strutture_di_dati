public class Tartaglia {
    private final int DIM = 100;
    public long C[][] = new long[DIM][DIM];


    public void compute(int n) {
        for (int i=0; i<n; i++) {
            C[i][0] = 1;
            C[i][i] = 1;
        }

        for (int i=2; i<n; i++) {
            for (int j=1; j<i; j++) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }


    public static void main(String args[]) {
        Tartaglia t = new Tartaglia();
        t.compute(10);

        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                System.out.println("C(" + i + "," + j + ") = " + t.C[i][j]);
            }
        }
    }
}
