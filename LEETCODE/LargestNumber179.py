class Num:
    def __init__(self, val):
        self.val = str(val)
    
    def __lt__(self, other):
        return self.val + other.val < other.val + self.val


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = [Num(num) for num in nums]
        nums.sort(reverse=True)
        
        return '0' if nums[0].val == '0' else ''.join(num.val for num in nums)
