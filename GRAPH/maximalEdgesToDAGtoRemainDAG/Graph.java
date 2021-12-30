
//Program to find maximum edges after adding
// which graph still remains a DAG
import java.util.*;

public class Graph {

    int V;

    ArrayList<ArrayList<Integer>> adj;

    int[] indegree;

    Graph(int v) {
        this.V = v;
        indegree = new int[V];
        adj = new ArrayList<>(V);

        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<Integer>());
            indegree[i] = 0;
        }
    }

    public void addEdge(int v, int w) {
        adj.get(v).add(w);

        indegree[w]++;
    }

    public List<Integer> topologicalSort() {

        List<Integer> topological = new ArrayList<>(V);
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }

        while (!q.isEmpty()) {
            int t = q.poll();

            topological.add(t);

            for (int j : adj.get(t)) {
                indegree[j]--;

                if (indegree[j] == 0) {
                    q.add(j);
                }
            }

        }

        return topological;

    }

    public void maximumEdgeAddtion() {
        boolean[] visited = new boolean[V];
        List<Integer> topo = topologicalSort();

        for (int i = 0; i < topo.size(); i++) {
            int t = topo.get(i);

            for (Iterator<Integer> j = adj.get(t).listIterator(); j.hasNext();) {
                visited[j.next()] = true;
            }

            for (int j = i + 1; j < topo.size(); j++) {
                if (!visited[topo.get(j)]) {
                    System.out.print(t + "-" + topo.get(j) + " ");
                    System.out.println();
                }

                visited[topo.get(j)] = false;
            }
        }
    }

    public static void main(String[] args) {

        Graph g = new Graph(6);
        g.addEdge(5, 2);
        g.addEdge(5, 0);
        g.addEdge(4, 0);
        g.addEdge(4, 1);
        g.addEdge(2, 3);
        g.addEdge(3, 1);

        g.maximumEdgeAddtion();
        System.out.print("\n");
        return;
    }
}
