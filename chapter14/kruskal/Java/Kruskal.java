/*
 * Chapter 14
 * Paragraph 3.1
 *
 * Kruskal minimum spanning tree algorithm
 */

import java.util.ArrayList;
import java.util.Set;
import java.util.TreeSet;
import java.util.Collections;


class Edge implements Comparable<Edge> {
    public int u;
    public int v;
    public int weight;

    public int compareTo(Edge e) {
        return weight - e.weight;
    }
}


public class Kruskal {
    public static void compute(ArrayList<Edge> A, int n, int m, Set<Edge> T) {
        Mfset mf = new Mfset(n);

        Collections.sort(A);

        int c = 0;
        int i = 0;

        while (c < n-1 && i<=m) {
            if (mf.find(A.get(i).u) != mf.find(A.get(i).v)) {
                mf.merge(A.get(i).u, A.get(i).v);
                T.add(A.get(i));
                c++;
            }
            i++;
        }
    }


    public static void main(String[] args) {
        Edge tmp;
        ArrayList<Edge> edges = new ArrayList<Edge>();

        tmp = new Edge(); tmp.u = 1; tmp.v = 2; tmp.weight = 9; edges.add(tmp);
        tmp = new Edge(); tmp.u = 1; tmp.v = 3; tmp.weight = 6; edges.add(tmp);

        tmp = new Edge(); tmp.u = 2; tmp.v = 3; tmp.weight = 11; edges.add(tmp);
        tmp = new Edge(); tmp.u = 2; tmp.v = 4; tmp.weight = 1; edges.add(tmp);
        tmp = new Edge(); tmp.u = 2; tmp.v = 5; tmp.weight = 20; edges.add(tmp);

        tmp = new Edge(); tmp.u = 3; tmp.v = 4; tmp.weight = 2; edges.add(tmp);
        tmp = new Edge(); tmp.u = 3; tmp.v = 6; tmp.weight = 18; edges.add(tmp);

        tmp = new Edge(); tmp.u = 4; tmp.v = 5; tmp.weight = 13; edges.add(tmp);
        tmp = new Edge(); tmp.u = 4; tmp.v = 6; tmp.weight = 28; edges.add(tmp);
        tmp = new Edge(); tmp.u = 4; tmp.v = 7; tmp.weight = 15; edges.add(tmp);

        tmp = new Edge(); tmp.u = 5; tmp.v = 7; tmp.weight = 3; edges.add(tmp);

        tmp = new Edge(); tmp.u = 6; tmp.v = 7; tmp.weight = 25; edges.add(tmp);

        Set<Edge> result = new TreeSet<Edge>();
        Kruskal.compute(edges, 7, edges.size(), result);

        for (Edge it : result) {
            System.out.println(it.u + " - " + it.v);
        }
    }
}
