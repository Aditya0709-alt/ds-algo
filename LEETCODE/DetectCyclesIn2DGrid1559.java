/**
The idea is to use the Union-Find data structure and flatten the grid into a 1D structure 

A cycle exists if:
- You try to union two cells with the same character, and
- They are already connected (i.e., same parent)

Also, to avoid false cycle detection, only check right and down neighbors (not all 4 directions).
**/
public class DetectCyclesIn2DGrid1559 {
    public boolean containsCycle(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        UnionFind uf = new UnionFind(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int current = i * n + j;

                // Check right neighbor
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
                    int right = i * n + (j + 1);
                    if (!uf.findAndUnite(current, right)) {
                        return true; // cycle detected
                    }
                }

                // Check down neighbor
                if (i + 1 < m && grid[i][j] == grid[i + 1][j]) {
                    int down = (i + 1) * n + j;
                    if (!uf.findAndUnite(current, down)) {
                        return true; // cycle detected
                    }
                }
            }
        }

        return false;
    }
}

class UnionFind {
    int[] parent;
    int[] size;

    public UnionFind(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int findset(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findset(parent[x]);
    }

    public void unite(int x, int y) {
        if (size[x] < size[y]) {
            int temp = x; x = y; y = temp;
        }
        parent[y] = x;
        size[x] += size[y];
    }

    public boolean findAndUnite(int x, int y) {
        int parentX = findset(x);
        int parentY = findset(y);
        if (parentX != parentY) {
            unite(parentX, parentY);
            return true;
        }
        return false;
    }
}
