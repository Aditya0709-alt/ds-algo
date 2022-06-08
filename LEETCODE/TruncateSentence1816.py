class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        l = s.split(" ")
        ans = " "
        return ans.join(l[:k])
