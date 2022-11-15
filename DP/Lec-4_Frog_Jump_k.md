
```python

def frogJumpUtil(curr, target, heights, dp):
  if curr > target:
    return 1e + 9
  if curr == target:
    return 0
  if dp[curr] != -1:
    return dp[curr]
  minCost = 1e + 9
  for i in range(1, k+1):
    stepK = abs(heights[i + curr] - heights[curr]) + frogJumpUtil(curr+i, target, heights, dp)
    minCost = min(stepK, minCost)
  dp[curr] = minCost
  return dp[curr]
  
  # Time Complexity: O(N) * O(K)
  # Space Complexity: O(N) + O(N)

```



