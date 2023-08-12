// Approach
// We use a find variable to get the difference between the target and the remaining elements. 
// If any element is equal to find, we return the two sum indices array. If no such pair exists, we return null
// Time Complexity: O(N^2)
// Space Compexity: O(2)


public class TwoSumII167 {
   public int[] twoSum(int[] numbers, int target) {
          int len = numbers.length;
          for(int i = 0; i < len - 1; i++){
              int find = target - numbers[i];
              System.out.println(find);
              for(int j = i+1; j < len; j++){
                  if(numbers[j] == find){
                      return new int [] {i+1,j+1};
                  }
              }
               if(numbers[i] > find){
                      break;
                  }
          }
          return null;
  }
}
