
# This algorithm uses a breadth-first search approach to find the shortest alternating paths in the graph. 
# It starts from node 0 and uses two separate lists, red_graph and blue_graph, to store the red and blue edges respectively. 
# The queue stores nodes to be visited and it starts with node 0 for both red and blue edges. 
# The algorithm adds nodes to the queue based on their color, alternating between red and blue edges, until all nodes have been visited or there are no more nodes left to visit. 
# If a node has already been visited, it is ignored. 
# The depth of each node is stored in the result array, res, and is updated when the node is visited for the first time. 
# Finally, the result array is returned.

# Time Complexity: O(V+E)

from collections import defaultdict
from collections import deque

class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        redGraph = defaultdict(list)
        blueGraph = defaultdict(list)
        
        for a, b in redEdges:
            redGraph[a].append(b)
            redGraph[b].append(a)
        
        for u, v in blueEdges:
            blueGraph[u].append(v)
            blueGraph[v].append(u)
            
        ans = [-1]*n
        
        queue = deque([(0, 0, 0), (0, 1, 0)])
        visited = set()
        
        while queue:
            node, color, depth = queue.popleft()
            
            
            if (node, color) in visited:
                continue
                visited.add((node, color))
                
                ans[node] = depth
                
                if color == 0:
                    for v in redGraph[node]:
                        queue.append(v,0,depth+1)
                else:
                    for v in blueGraph[node]:
                        queue.append(v,1,depth+1)
        return ans
        
