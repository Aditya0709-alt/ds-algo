class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs = sorted(pairs, key= lambda x:x[1])
        p1, p2, res = 0, 0, 1
        
        while p2 < len(pairs):
            if (pairs[p1][1] < pairs[p2][0]):
                p1 = p2
                p2 += 1
                res += 1
            else:
                p2 += 1
        return res
