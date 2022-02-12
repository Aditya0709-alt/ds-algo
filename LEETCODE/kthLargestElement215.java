import java.util.PriorityQueue;
class Solution {
    public int findKthLargest(int[] nums, int k) {
        
        PriorityQueue<Integer> q = new PriorityQueue<Integer>();
        for(int i : nums){
        q.add(i);
        
        while(!q.isEmpty() && q.size() > k){
        q.poll();
            }
        }
        return q.peek();
    }
}
