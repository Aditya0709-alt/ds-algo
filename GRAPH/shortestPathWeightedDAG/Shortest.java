import java.util.*;

class Shortest {
    static int MAX = Integer.MAX_VALUE;

    class AdjListNode {
        private int v;
        private int weight;

        AdjListNode(int v, int weight) {
            this.v = v;
            this.weight = weight;
        }

        int get_v() {
            return v;
        }

        int getWeight() {
            return weight;
        }
    }

    class Graph {
        private int V;
        private LinkedList<AdjListNode> adj[];

        Graph(int v) {
            v = V;
            adj = new LinkedList[V];
            for (int i = 0; i < V; i++) {
                adj[i] = new LinkedList<AdjListNode>();
            }
        }

        void addEdge(int u, int v, int weight) {
            AdjListNode node = new AdjListNode(v, weight);
            adj[u].add(node);
        }

        void topologicalSortUtil(int v, Boolean visited[], Stack stack) {
            visited[v] = true;
            Integer i;

        }
    }
}