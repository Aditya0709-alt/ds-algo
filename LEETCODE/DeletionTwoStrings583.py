# From both strings word1 and word2 only those haracter will be deleted which are not present in the other string.

# For this we find LCS i.e. Longest Common Subsequence.

# We create a matrix of size (m+1)*(n+1) and make first row and column equal to zero.

# If i element of word1 is equal to j element of word2 we make the index of matrix[ i + 1 ][ j + 1 ] equal to 1 + diagonally previous element
# If they are not equal equal then matrix value at that index will be maximum of element above or to the left of that matrix.
# The very last element of that matrix will give us the length of LONGEST COMMON SUBSEQUENCE.

# Time Complexity: O(m*n)


class Solution:       
    def minDistance(self, word1: str, word2: str) -> int:
        if len(word1)>len(word2):
            word2,word1=word1,word2        
        
        m,n=len(word1),len(word2)
        prev=[0] * (m+1)
        
        for i in range(n-1, -1, -1):
            curr=[0] * (m+1)
            for j in range(m-1, -1, -1):
                if word1[j] == word2[i]:
                    curr[j]=1 + prev[j+1]
                else:
                    curr[j]=max(curr[j+1], prev[j])
            prev=curr
        return m + n - 2*prev[0]
