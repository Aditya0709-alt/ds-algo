class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        res=0
        cur=0
        s=set()
        l=0
        for r in range(len(nums)):
            while nums[r] in s:
                s.remove(nums[l])
                cur=cur-nums[l]
                l=l+1
            s.add(nums[r])
            cur=cur+nums[r]
            res=max(res,cur)
        return res
