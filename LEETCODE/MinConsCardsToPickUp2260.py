
# Approach

# We traverse the array
# Check if the same elements exist in the dictionary, we get the range of cards and compare with the recent pair sequences (i - seen[c] + 1) 
# Return the minimum value

# Time Complexity: O(N)
# Space Complexity: O(N) (Auxiliary Space needed for dictionary)

class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        seen = {}
        INF = 10**30
        res = INF
        N = len(cards)
        
        for i,c in enumerate(cards):
            if c in seen:
                res = min(res, i - seen[c] + 1)
                
            seen[c] = i
        if res == INF:
            return -1
        return res
