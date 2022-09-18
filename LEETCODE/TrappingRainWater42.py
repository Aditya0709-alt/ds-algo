class Solution:
    def trap(self, height: List[int]) -> int:

        lo, hi = 0, len(height)-1
        left_max, right_max = 0, 0
        sum_total = 0
        while lo < hi:
            left_max = max(left_max, height[lo])
            right_max = max(right_max, height[hi])

            if left_max < right_max:
                sum_total += max(left_max - height[lo+1], 0)
                lo += 1
            else:
                sum_total += max(right_max - height[hi - 1], 0)
                hi -= 1

        return sum_total
