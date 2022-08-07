# Approach

# Bottom-up DP approach

# Initialize all the vowels to 1 and while iterating from 1 to n, add the count of vowels based on the previous count.

# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
    def countVowelPermutation(self, n: int) -> int:

        # Initialize all vowels counts to 1
		# This is n==1 case
        a, e, i, o, u = 1, 1, 1, 1, 1

        # Iterate from 2 to n
        for _ in range(2, n + 1):
            a, e, i, o, u = e + i + u, a + i, e + o, i, i + o

        # Return the sum of all counts of all vowels
        return (a + e + i + o + u) % 1000000007
