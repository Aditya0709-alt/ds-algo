## Recursion Practice

### Printing Subsequences

This includes contiguous and non-contiguous subsequences. 


```java
import java.util.*;

public class Main {
    
    public static void printSubsquence(int [] arr, int index, ArrayList<Integer> path){
        
        if (index >= arr.length){
            if (path.size() > 0){
                System.out.print(path + " ");
            }
        } else {
            // pick the current index
            printSubsquence(arr, index + 1, path);
            
            path.add(arr[index]);
            
            // don't pick the current index
            printSubsquence(arr, index+ 1, path);
            
            path.remove(path.size() - 1);
        }
        return;
    }
    
    public static void main(String [] args){
        int [] arr = {1,2,3};
        
        ArrayList<Integer> path = new ArrayList<Integer>();
        
        printSubsquence(arr, 0, path);
    }
}
```


In an online game, N blocks are arranged in a hierarchical manner. Each block is given an ID from 1 to N. A block may be further connected to other blocks. All the blocks are connected by N-1 connections. Each block is assigned a specific point value. A player starts from a block (S). She must move forward from each block to a directly connected block until she reaches the final block, which has no further connection. When the player lands on a block, she collects the point value of that block. The player’s score is calculated as the product of block points that the player collects. The player who earns the maximum score wins the game. Write an algorithm to find the maximum score of the winner.

```python

def max_score(N, S, P, connections):
    graph = [[] for _ in range(N + 1)]
    for u, v in connections:
        graph[u].append(v)
        graph[v].append(u)

    scores = [0] * (N + 1)
    scores[S] = P[S - 1]
    max_score = P[S - 1]

    def dfs(node):
        nonlocal max_score
        for neighbor in graph[node]:
            scores[neighbor] = scores[node] * P[neighbor - 1]
            max_score = max(max_score, scores[neighbor])
            dfs(neighbor)

    dfs(S)
    return max_score
```

This algorithm uses a depth-first search (DFS) to traverse the blocks and find the maximum score. The input to the algorithm consists of the number of blocks N, the starting block S, the block point values P, and a list of connections between the blocks connections.

The connections are represented as an adjacency list, where each block is represented as an index in the list and its connected blocks are stored as a list of indices. The DFS function starts from the starting block S, and for each block, it calculates the score by multiplying the point value of the current block with the point value of the previous block. The maximum score is stored in the max_score variable and updated during the DFS.

At the end of the algorithm, the max_score variable will contain the maximum score of the winner.



