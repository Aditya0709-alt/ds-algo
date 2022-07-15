
# To find the maximum area we need to explore or visit the neighbours of each cell i.e. visit the vertices of a graph. 
# The most popular ways of doing so are DFS and BFS.
# The idea is that whenever we step on land (value 1) we start exploring our neighbors, and we do this until we explore the whole island.
# In order to not visit the same cells twice, we will have a visited matrix that will remember the cells that we visited.




class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        R = len(grid)
        C = len(grid[0])
        
        done  = [[False] * C for _ in range(R)]
        directions = [(0,1),(1,0),(0,-1),(-1,0)]
        
        def calc(sx,sy):
            q = collections.deque()
            count = 0
            
            def enqueue(x,y):
                if not done[x][y]:
                    done[x][y] = True
                    q.append((x,y))
                    nonlocal count
                    count += 1
                    
            enqueue(sx,sy)
            
            while len(q) > 0:
                x, y = q.popleft()
                
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    
                    if 0 <= nx < R and 0 <= ny < C and not done[nx][ny] and grid[nx][ny] == 1:
                        enqueue(nx,ny)
            return count
                        
        best = 0
        for i in range(R):
            for j in range(C):
                if grid[i][j] == 1 and not done[i][j]:
                    best = max(best,calc(i,j))
        return best

#  Time Complexity: O(R*C)
  
                    
 
            
