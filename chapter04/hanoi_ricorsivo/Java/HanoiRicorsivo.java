/*
 * Chapter 4
 * Paragraph 4
 *
 * Hanoi-ricorsiva
 */

public class HanoiRicorsivo {
    public static void doHanoi(int n, int origine, int destinazione, int intermedio) {
        if (n == 1) {
            System.out.println("Trasferisci un disco da " + origine + " a " + destinazione);
        }
        else {
            doHanoi(n-1, origine, intermedio, destinazione);
            System.out.println("Trasferisci un disco da " + origine + " a " + destinazione);
            doHanoi(n-1, intermedio, destinazione, origine);
        }
    }

    public static void main(String[] args) {
        doHanoi(3, 1, 3, 2);
    }
}
