# Approach
# The sorted() method sorts strings alphabetically and lists numerically. 
# An anagram is word derived from another word that contains all the letters present in the original word 
# and has the same count for repeating letters.

# Time Complexity: The sorted() function implements the Timsort algorithm which runs in O(NlogN) time.
# Space Complexity: O(1)


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
