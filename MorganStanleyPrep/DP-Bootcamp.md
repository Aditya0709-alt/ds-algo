
## Dynamic Programming Practice

### House Robber

A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.


## Ninja's Training

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
        
