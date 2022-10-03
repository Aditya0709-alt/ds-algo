Time Complexity: O(N^2)

class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        N = len(colors)
        
        ans = 0
        
        for i in range(N):
            ch = colors[i]
            total = 0
            maxValue = 0
            
            while (i < N and colors[i] == ch):
                maxValue = max(maxValue, neededTime[i])
                total += neededTime[i]
            ans += total - maxValue
        return ans
 

# Optimized approach (Two pointer method)
# We take two pointers and compare the neededTime of the consecutive characters, if they are same then add the minimum to our ans
# Time Complexity: O(N)
# Space Complexity: O(1)
  

  
class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        ans = 0
        j = 0
        
        for i in range(1,len(colors)):
            if (colors[i] == colors[j]):
                if (neededTime[i] < neededTime[j]):
                    ans += neededTime[i]
                else:
                    ans += neededTime[j]
                    j = i
            else:
                j = i
        return ans
    
   
