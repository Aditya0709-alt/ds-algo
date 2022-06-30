'''
Approach

We can place houses on both sides of the street. The number of ways of placing houses on eaxh side of the street is the Fibonacci sequence. Thus, the answer for placing houses on both sides of the street is 
fibonacci * fibonacci

Time Complexity: O(N)
Space Complexity: O(1)
'''

class Solution:
  def countHousePlacements(self, n):
        a, b, mod = 1, 1, 10**9 + 7
        for i in range(n):
            a, b = b, (a + b) % mod
        return b * b % mod
