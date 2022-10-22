```python

#Recursion
arr = [10,20,30,10]
def frogJump(n: int):
    if n == 0:
        return 0 
    left = frogJump(n-1) + abs(arr[n] - arr[n-1])
    right = 1e+9
    if n > 1:
        right = frogJump(n-2) + abs(arr[n] - arr[n-2])
    
    return min(left,right)
    
 #Memoization (Top-down approach)
 
 import functools
 @functools.lru_cache()
 def frogJump(n: int):
 dp = [-1]*n
    if n == 0:
        return 0 
    if dp[n] != -1:
      return dp[n]
    left = frogJump(n-1) + abs(arr[n] - arr[n-1])
    right = 1e+9
    if n > 1:
        right = frogJump(n-2) + abs(arr[n] - arr[n-2])
    dp[n] = min(left,right)
    return dp[n]
  
  #Tabulation (Bottom-up approach)
  heights = [30,10,60,10,60,50]
  
  def frogJump(n: int) -> int:
    dp = [-1]*n
    
    dp[0] = 0
    
    for i in range(1,n):
      stepTwo = 1e+9
      stepOne = dp[i-1] + abs(heights[i] - heights[i-1])
      if i > 1:
        stepTwo = dp[i-2] + abs(heights[i] - heights[i-2])
      
      dp[i] = min(stepOne, stepTwo)
    
    return dp[n-1]
    
  #Time Complexity: O(N)
  #Space Complexity: O(N)
```
