class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        while len(nums) > 1:
            newNums = []
            
            N = len(nums)
            for i in range(0,N,2):
                a = nums[i]
                b = nums[i+1]
                
                p = i // 2
                if p % 2 == 0:
                    newNums.append(min(a,b))
                else:
                    newNums.append(max(a,b))
            nums = newNums
        return nums[0]
