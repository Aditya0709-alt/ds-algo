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
