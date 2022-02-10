class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> count;
        map<int, int> dict;

        for(int i = 0; i < nums.size(); i++) {
            if(dict.find(nums[i]) != dict.end()) {
                if(find(count.begin(), count.end(), (dict[nums[i]],nums[i])) != count.end()) continue;
                count.push_back((dict[nums[i]],nums[i]));
            }
            dict[nums[i]+k] = nums[i];
        }
        
        return count.size();
        
    }
};
