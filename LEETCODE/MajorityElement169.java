/*
Use hashmap to keep count of each element and then use simple if else check
*/

class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> countMap = new HashMap<>();
        

        for (int num : nums) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
            if (countMap.get(num) > nums.length / 2) {
                return num;
            }
        }

        throw new IllegalArgumentException("No majority element found.");
    }
        
}
