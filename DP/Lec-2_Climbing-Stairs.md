
```python

#Recursion

def cs(curr: int, target: int) -> int:
  if curr == target:
    return 1
  if curr > target:
    return 0
  return cs(curr+1, target) + cs(curr+2, target)


#Memoization (Top-down approach)

import functools

@functools.lru_cache(maxsize=None)
def cs(curr: int, target: int) -> int:
  dp = [-1]*50
  
  if curr == target:
    return 1
  if curr > target:
    return 0
  if dp[curr] != -1:
    return dp[curr]
  return dp[curr] = cs(curr+1, target) + cs(curr+2, target)
 
 
 #Tabulation (Bottom-up approach)
 
 def cs(target: int) -> int:
    dp = [-1]*(target+2)
    
    dp[target+1] = 0
    dp[target]= 1
    
    for i in reversed(range(0,n)):
      dp[i] = dp[i+1] + dp[i+2]
    
    return dp[target]
  

#Time Complexity: O(N)
#Space Complexity: O(N)
  
```
