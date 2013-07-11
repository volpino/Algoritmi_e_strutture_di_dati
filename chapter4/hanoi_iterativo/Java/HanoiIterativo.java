/*
 * Chapter 4
 * Paragraph 4
 *
 * Hanoi-iterativa
 */


import java.util.*;


public class HanoiIterativo {
    public static void doHanoi(int n, int origine, int destinazione, int intermedio) {
        int temp;
        Stack<int[]> s = new Stack();
        boolean finedelmondo = false;
        while (!finedelmondo) {
            while (n != 1) {
                int[] array = new int[]{n, origine, destinazione, intermedio};
                s.push(array);
                n--;

                temp = destinazione;
                destinazione = intermedio;
                intermedio = temp;
            }
            System.out.println("Trasferisci un disco da " + origine + " a " + destinazione);
            if (s.empty()) {
                finedelmondo = true;
            }
            else {
                int[] array = s.pop();
                n = array[0];
                origine = array[1];
                destinazione = array[2];
                intermedio = array[3];
                System.out.println("Trasferisci un disco da " + origine + " a " + destinazione);
                n--;
                temp = origine;
                origine = intermedio;
                intermedio = temp;
            }
        }
    }

    public static void main(String[] args) {
        doHanoi(3, 1, 3, 2);
    }
}
