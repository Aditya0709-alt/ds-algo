import java.lang.reflect.Array;
import java.util.*;

class Graph {
    int v;

    List<Integer> adj[];

    public Graph(int v) {
        this.v = v;
        adj = new ArrayList[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new ArrayList<Integer>();
        }
    }

    public void addEdge(int u, int v) {
        adj[u].add(v);
    }

    public void topologicalSort() {
        int[] indegree = new int[v];

        for (int i = 0; i < v; i++) {
            ArrayList<Integer> temp = (ArrayList<Integer>) adj[i];
            for (int node : temp) {
                indegree[node]++;
            }
        }

        Queue<Integer> q = new LinkedList<Integer>();
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }

        int count = 0;
        Vector<Integer> topOrder = new Vector<Integer>();
        while (!q.isEmpty()) {
            int u = q.poll();
            topOrder.add(u);

            for (int a : adj[u]) {
                if (--indegree[a] == 0) {
                    q.add(a);
                }
            }
            count++;
        }

        if (count != v) {
            System.out.print("There is a cycle");
            return;
        }

        for (int i : topOrder) {
            System.out.print(i + " ");
        }
    }
}

public class Main {

    public static void main(String[] args) {
        Graph g = new Graph(6);
        g.addEdge(5, 2);
        g.addEdge(5, 0);
        g.addEdge(4, 0);
        g.addEdge(4, 1);
        g.addEdge(2, 3);
        g.addEdge(3, 1);
        g.topologicalSort();
        System.out.println();
    }
}