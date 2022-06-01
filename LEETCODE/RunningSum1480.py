class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        res = []
        x = 0
        for i in range(len(nums)):
            x += nums[i]
            res.append(x)
            
        return res
