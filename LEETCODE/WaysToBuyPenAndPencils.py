class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        count = 0
        curr = 0
        
        while (curr <= total):
            count += ((total-curr)//cost2)+1
            curr += cost1
            
        return count
        
