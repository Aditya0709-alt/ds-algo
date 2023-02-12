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


