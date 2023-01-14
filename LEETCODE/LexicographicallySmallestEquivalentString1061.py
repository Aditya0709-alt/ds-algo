# Approach

# We are making use of the basic template for disjoint set, for creating an equivalence relationship between the characters of the two input strings. 
# The idea is to group the characters in s1 and s2 which are equivalent and replace them with the smallest character in the group.

# Time Complexity: O(NlogN) ...Union-by-size complexity 
# Space Complexity: O(N) ...because of disjoint set

class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        def find(c):
            i = ord(c) - ord('a')
            while root[i] != i:
                i = root[i]
                
            return i
        
        root = list(range(26))
        for c1, c2 in zip(s1, s2):
            r1 = find(c1)
            r2 = find(c2)
            if r1 > r2:
                r1, r2 = r2, r1

            root[r2] = r1
        
        return "".join(chr(ord('a') + find(c)) for c in baseStr)
  
  



