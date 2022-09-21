
Time Complexity: O(n+p), where n is the length of nums vector and p is the length of queries vector


class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                sum += nums[i];
            }
        }
        
        
        for(int i = 0; i < queries.size();i++){
            int val = queries[i][0];
            int index = queries[i][1];
            
            if(nums[index] % 2 == 0){
                sum -= nums[index];
            }
            nums[index] += val;
            
            if(nums[index] % 2  == 0){
                sum += nums[index];
            }
            res.push_back(sum);
        }
        return res;
    }
};

