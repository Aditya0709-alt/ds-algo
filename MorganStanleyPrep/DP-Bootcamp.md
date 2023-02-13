
## Dynamic Programming Practice

### House Robber

A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.


### Ninja's Training

Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size 3.N ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

The formula for calculating the maximum merit points is

```
dp[i][j] = max(dp[i-1][k]) + POINTS[i][j]
```

```python3
def maxMeritPoints(N, points):
    
    dp = [[0 for i in range(3)] for j in range(N)]
    
    dp[0][0] = points[0][0]
    dp[0][1] = points[0][1]
    dp[0][2] = points[0][2]
    
    
    for i in range(1,N):
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + points[i][0]
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + points[i][1]
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + points[i][2]
        
    return max(dp[N-1][0], dp[N-1][1], dp[N-1][2])
      
print(maxMeritPoints(3,[[1,50,11],[10,100,40],[20,78,3]])) 
```

### Unique Paths

You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].

To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].


We use a 2-D list of size M X N and two indices. We start from the position (M-1,N-1) and move either up or left. The formula for moving up or left is
```
dp[i][j]  = dp[i][j] + dp[i-1][j] (For moving up)
dp[i][j]  = dp[i][j] + dp[i][j-1] (For moving left)
```

```python3
# def uniquePathsRec(i,j):
    
#     if i == 1 and j == 1:
#         return 1 
#     if i < 0 or j < 0:
#         return 0
    
#     up, left = 0, 0
    
#     up = uniquePaths(i-1,j)
#     left = uniquePaths(i,j-1)
            
#     return up + left
    
# print(uniquePathsRec(7,8))


def uniquePathsDP(M,N):
    dp = [[0 for a in range(M+1)] for b in range(N+1)]
    
    dp[0][0] = 1
    
    
        
    up = 0
    left = 0
    
    for i in range(M):
        for j in range(N):
            dp[i][j] += dp[i-1][j]
            dp[i][j] += dp[i][j-1]
    
    return dp[M-1][N-1]
    
print(uniquePathsDP(7,8))
```

## Unique Paths with Obstacles


```python3 
def uniquePathsRec(i,j, grid, dp):
    
    if i > 0 and j > 0 and grid[i][j] == -1:
        return 0
    if i == 1 and j == 1:
        return 1 
    if i < 0 or j < 0:
        return 0
    if dp[i][j] == -1:
        return dp[i][j]
    
    up, left = 0, 0
    
    up = uniquePathsRec(i-1,j, grid,dp)
    left = uniquePathsRec(i,j-1,grid,dp)
            
    dp[i][j] = up + left
    
    return dp[i][j]
    
def uniquePaths(n,m,grid):
    dp = [[-1 for j in range(m)] for i in range(n)]
    return uniquePathsRec(n-1, m-1, grid, dp)

grid = [[0,0,0],[0,-1,0],[0,0,0]]
n = len(grid)
m = len(grid[0])
```


        
