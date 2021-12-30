import java.util.*;

public class bp {

    static class Pair {
        int first, second;

        Pair(int f, int s) {
            first = f;
            second = s;
        }
    }

    static boolean isBipartite(int V, ArrayList<ArrayList<Integer>> adj) {

        int col[] = new int[V];
        Arrays.fill(col, -1);

        Queue<Pair> q = new LinkedList<Pair>();

        for (int i = 0; i < V; i++) {

            if (col[i] == -1) {

                q.add(new Pair(i, 0));
                col[i] = 0;

                while (!q.isEmpty()) {
                    Pair p = q.peek();
                    q.poll();

                    int v = p.first;

                    int c = p.second;

                    for (int j : adj.get(v)) {

                        if (col[j] == c)
                            return false;

                        if (col[j] == -1) {

                            col[j] = (c == 1) ? 0 : 1;
                            q.add(new Pair(j, col[j]));
                        }
                    }
                }
            }
        }

        return true;
    }

    public static void main(String args[]) {

        int V, E;
        V = 4;
        E = 8;

        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<Integer>());
        }

        adj.get(0).add(1);
        adj.get(0).add(3);

        adj.get(1).add(0);
        adj.get(1).add(2);

        adj.get(2).add(1);
        adj.get(2).add(3);

        adj.get(3).add(0);
        adj.get(3).add(2);

        boolean ans = isBipartite(V, adj);

        if (ans)
            System.out.println("Yes");

        else
            System.out.println("No");

    }
}
