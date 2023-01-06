# Time Complexity: O(NlogN)
# Space Complexity: O(1)

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        ans = 0
        # Sort the costs array for maximizing the number of ice creams that can be bought
        costs.sort()
        for i in range(len(costs)):
            if costs[i] <= coins:
                ans += 1 
                coins -= costs[i]
            else:
                continue
        return ans
