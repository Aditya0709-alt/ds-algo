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



