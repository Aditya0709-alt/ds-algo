// Approach

// We maintain a left and right pointer and simultaneously increment the left numbers and decrement the right numbers. We do this until left < right

// Time Complexity: O(NlogN)
// Space complexity: O(1)
 

class MinMovesToEqualArray462 {
    public int minMoves2 (int[] nums) {
        Arrays.sort (nums);
        int left = 0, right = nums.length - 1, moves = 0;
        while (left < right)
            moves += nums [right--] - nums [left++];
        return moves;
    }
}


