/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
*/

/*
Brute-force solution -> As the heights are having a difference of 1 unit, for a pair (height1,height2) we need to consider the minimum of these two.
Using two for loops we check for all feasible solutions and return the maximum of all the solutions.

Time Complexity: O(n^2) as there are two for loops 
Space Complexity: O(1) as no extra arrays are required
*/

public class Solution
{
    static int min(int a, int b){
        return (a < b) ? a : b;
    }
    
    static int max(int a , int b){
        return (a > b) ? a : b;
    }
    static int maxArea(int [] height){
        int n = height.length;
        int ans = 0;
        for(int i = 0; i < n ; i++){
            for(int j = i+1; j < n; j++){
                int area = min(height[i], height[j])*(j - i);
                ans = max(ans,area);
            }
        }
        return ans;
    }
    
 /*
 Optimized solution -> We use two pointers left and right and store the smaller of heights. 
 We calculate area and store the maximum of area at every iteration. 
 If the left height is greater, increment the right pointer and vice versa.
 We do this until my left pointer is not greater than my right pointer.
 
 Time Complexity: O(n) as only a single while loop is used
 Space Complexity: O(1) as no extra arrays are required
 */

class Solution {
    static int max(int a, int b){
        return (a > b) ? a : b;
    }
    
    static int min (int a, int b){
        return (a < b) ? a : b;
    }
    
    static int maxArea(int [] height){
        int l = 0, r = height.length-1;
        int area = 0;
        while(l < r){
            int small = min(height[l], height[r]);
            area = max(area,small*(r-l));
            
            if(height[l] < height[r]){
                l++;
            } else {
                r--;
            }        
        }
        return area;
    }
}
    
