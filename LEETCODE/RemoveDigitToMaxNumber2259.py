class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        ans = ""
        
        for i, c in enumerate(number):
            if digit == c:
                curr = number[:i] + number[i+1:]
                
                if ans == "" or curr > ans:
                    ans = curr
        return ans
