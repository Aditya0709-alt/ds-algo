# Problem
# You are given an integer array nums and an integer x. 
# In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
# Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

# Approach
# The problem is similar to Max Sum Subarray Problem. Here, we find the largest subarray whose total is sum(nums) - x. 
# Then, we find the length of the largest subarray with the total. The minimum number of operations is n - len(largest_subarray)

# Time Complexity: O(N) (Using Sliding Window Method)
# Space Complexity: O(1) (In-place)


class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        total = sum(nums)
        remainder = total - x
        n = len(nums)
        largest_subarray_len = -1
        current_sum = 0

        j = 0
        for i in range(n):
            current_sum += nums[i]
            while current_sum > remainder and j <= i:
                current_sum -= nums[j]
                j += 1
            if current_sum == remainder:
                largest_subarray_len = max(largest_subarray_len, i - j + 1)

        if largest_subarray_len == -1:
            return largest_subarray_len

        return n - largest_subarray_len
