# Approach

# - Count the frequencies of each character.
# - Sort the frequencies so it's easy to find the next unused frequency.
# - Initialize next_unused_freq to s.length. There could be as many as s.length characters of the same frequency.
# - We can't add characters, so we always need to set next_unused_freq to be <=freq.
# - The number of deletions we need to make this frequency unique is freq - next_unused_freq.

# Time Complexity: O(n)
# Space Complexity: O(n)

class Solution:
    def minDeletions(self, s: str) -> int:
        frequencies = sorted(Counter(s).values(), reverse=True)
        
        deletions = 0
        next_unused_freq = len(s)
        
        for f in frequencies:
            next_unused_freq = min(next_unused_freq,f)
            deletions += f  - next_unused_freq
            
            if next_unused_freq > 0:
                next_unused_freq -= 1
                
        return deletions
