/*
Approach
We use a prefix and a suffix array. The prefix array is calculated using arr[i-1] * prefix[i-1]
Similarly, suffix is calculated using arr[i+1] * suffix[i+1]

The product of these arrays gives the product of all the elements except for the current element

This approach helps us get the result in O(N) time instead of using two for loops
*/


class Solution {
    public int[] productExceptSelf(int[] nums) {
        int [] prefix = new int[nums.length];
        int [] suffix = new int[nums.length];
        prefix[0] = suffix[nums.length - 1] = 1;
        for(int i = 1; i < nums.length; i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        for(int i = nums.length - 2; i >= 0; i--){
            suffix[i] = nums[i+1] * suffix[i+1];
        }
        int [] ans = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
}
