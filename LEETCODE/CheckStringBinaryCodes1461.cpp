class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> res;
        int len = s.size();
        int num = (1<<k);
        for(int i = 0; i+k <= len && res.size() != num; i++){
            res.insert(s.substr(i,k));
        }
        return res.size() == num;
    }
};
