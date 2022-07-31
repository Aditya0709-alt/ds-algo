# We will take note of the sum when the array is initialized.
# We update the sum when the array is updated.
# We calculate the sum from left to right either as sum 
# between those index or by subtracting the sum of 0 to left and right to end from the total sum, depending on which is smaller in length.

class NumArray:
    nums = []
    s = 0
    l = 0
    
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.s = sum(nums)
        self.l = len(nums)

    def update(self, index: int, val: int) -> None:
        self.s -= self.nums[index]
        self.nums[index] = val
        self.s += self.nums[index]

    def sumRange(self, left: int, right: int) -> int:
        if right - left > self.l // 2:
            ans = sum(self.nums[:left]) + sum(self.nums[right + 1:])
            return self.s - ans
        else:
            return sum(self.nums[left: right + 1])
