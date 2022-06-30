class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = []
        sum = 0
        
        for i in nums:
            if i > i + sum:
                ans.append(i)
                sum = i
            else:
                ans.append(i + sum)
                sum += i
        return max(ans)
