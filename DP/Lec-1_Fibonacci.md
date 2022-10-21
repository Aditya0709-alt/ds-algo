
```python
#Memoization using lru_cache decorator

import functools

@functools.lru_cache(maxsize=None)
def fib(num):
  if num < 2:
    return num
  else:
    return fib(num-1) + fib(num-2)
    
#Tabulation 

dp = [-1]*10

def fib(n):
  dp[0] = 0
  dp[1] = 1
  
  for i in range(2,n+1):
    dp[i] = dp[i-1] + dp[i-2]
  return dp[n]
  

Space Optimization
#Instead of using an array, we can use three pointers curr, prev and prev2

def fib(n):
  if n == 0 or n == 1:
    return n
   
  prev = 1
  prev2 = 0
  
  curr = -1
  
  for i in range(2,n+1):
    curr = prev + prev2
    prev2 = prev
    prev = curr
  
  return prev
  
#Time Complexity: O(N)
#Space Complexity: O(1)
```
