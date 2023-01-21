class Solution:
    def countDigits(self, num: int) -> int:
        count = 0
        temp = num
        while temp != 0:
            d = temp % 10
            temp //= 10
            
            if d > 0 and num % d == 0:
                count += 1
        return count
                
            
        
