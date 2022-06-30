'''
Approach

We maintain a lookup table for the array. Then, for each pair in the operations array, we maintain an 
index which stores the current element in the nums array for each iteration. 
Then, we replace the element in the nums array. An delete the element in the lookup table.

Time Complexity: O(N) (For creating the lookup table)
Space Complexity: O(N)
'''

class Solution:
    def arrayChange(self, nums: List[int], operations: List[List[int]]) -> List[int]:
        lookup = {}
        for i,x in enumerate(nums):
            lookup[x] = i
        
        for x,y in operations:
            index = lookup[x]
            
            nums[index] = y
            lookup[y] = index
            del lookup[x]
        return nums
