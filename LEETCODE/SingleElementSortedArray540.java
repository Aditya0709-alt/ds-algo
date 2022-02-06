class Solution {
	publicint singleNonDuplicate(int[] nums) {
        int l = 0, r = nums.length-1, mid=0;
        
        if( l > r) {
            return -1;
        }
        if (l == r) {
            return nums[l];
        }
        while(l < r) {
            mid =( l + r )/2;
            
            
            if(mid % 2 == 0) {
                if(nums[mid] == nums[mid+1]){
                    l = mid+2;
                }
                else {
                    r = mid;
                }
            }
            else {
                if(nums[mid] == nums[mid-1]) {
                    l = mid+1;
                }
                else {
                    r =  mid-1;
            }
        }
    }
    return nums[r];
}
	
