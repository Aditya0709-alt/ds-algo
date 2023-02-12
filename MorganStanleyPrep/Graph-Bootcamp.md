## Breadth-First Search

- Breadth-first search (BFS) is an algorithm for traversing or searching a tree, graph or any other data structure where connections between elements, called edges, can be determined. 
- BFS visits all the vertices of a graph or all the nodes of a tree at a given level before going deeper. 
- The algorithm starts at the root node and visits all the vertices at the current depth level before moving on to the next level.

```python3

from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
        
    def addEdge(self, u, v):
        self.graph[u].append(v)
        
    def BFS(self, s):
        visited = [False]*(max(self.graph) + 1)
        
        queue = []
        
        queue.append(s)
        
        visited[s] = True
        
        while queue:
            s = queue.pop(0)
            print(s, end=" ")
            
        for i in self.graph[s]:
            if visited[i] == False:
                queue.append(i)
                visited[i] = True       
```

## Depth-First Search

- Depth-first search (DFS) is a graph traversal algorithm used for searching or exploring all the vertices of a graph or a tree data structure in a depth-wise manner. 
- Unlike breadth-first search (BFS), which explores all vertices at a given level before going deeper, DFS visits a vertex and then explores as far as possible along each branch before backtracking.
- The algorithm starts at the root node and visits the first child node of that vertex. It continues to visit child nodes as far down the tree as possible before backtracking and visiting other siblings. This process is repeated until all vertices have been visited.




```python3

def DFSHelper(s, visited):
        visited.add(s)
        print(s, end=" ")
        
        for i in self.graph[s]:
            if i not in visited:
                self.DFSHelper(i,visited)
    
    def DFS(s):
        
        visited = set()
        
        self.DFSUtil(s, visited)
   
```

## Cycle Detection in an undirected graph using BFS

- It is not possible to detect a cycle in an undirected graph using BFS alone, as BFS is not designed for that purpose. 
- BFS is used for finding the shortest path between two vertices in a graph, not for detecting cycles. 
- However, cycles in an undirected graph can be detected using a modified version of BFS that keeps track of the parent vertex for each vertex that is explored. 
- When a vertex is explored, if its neighbor has already been discovered and is not its parent, then a cycle has been found. 
- This is because the neighbor cannot be its parent and also a vertex that was previously discovered, unless there is a cycle in the graph.

```python3

from collections import deque

def addEdge(adj: List[int], u, v):
    adj[u].append(v)
    adj[v].append(u)
    
def isCyclicConnected(adj: List[int], s, V, visited: List[int]):
    parent = [-1]*V 
    
    q = deque()
    
    visited[s] = True
    q.append(s)
    
    while q:
        u = q.pop()
        
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                q.append(v)
                parent[v] = u
            elif parent[u] != v:
                return True
    return False

def isCyclicDisconnected(adj: List[int], V):
    visited = [False]* V 
    
    for i in range(V):
        if not visited[i] and \
               isCyclicConnected(adj, i, V, visited):
            return True
    return False
    
```




