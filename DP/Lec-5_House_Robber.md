
```
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night. Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
```
```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

### Memoization (Top-down approach)

```python

# Time Complexity: O(N)
# Space Complexity: O(N) + O(N)

def nonAdjacent(curr: int, target: int, v: List[int], nums: List[int]) -> int:
  if curr > target:
    return 0
  if curr == target:
    return nums[curr]
  currKey = curr
  if v[currKey] != -1:
    return v[currKey]
  rob = nums[curr] + nonAdjacent(curr+2, target, v, nums)
  dontRob = nonAdjacent(curr+1, target, v, nums)
  
  v[currKey] = max(rob, dontRob)
  
  return v[currKey]
```

### Tabulation (Bottom-up approach)

```python


# Time Complexity: O(N)
# Space Complexity: O(N)

def houseRobber(nums: int) -> int:
  n = len(nums)
  dp = [0]*(n+1)
  
  dp[n-1]. 
  dp = [0]*(n+1)
  
  dp[n-1] = nums[n-1]
  
  
  for i in reversed(range(n-1)):
    rob = nums[i] + dp[i+2]
    dontRob = dp[i+1]
    dp[i] = max(rob, dontRob)
  
  return dp[0]
 
  
`` 
