class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        int n=pref.size();
        for(auto s : words)
        {
            if(s.size()>= pref.size())
            {
                if(s.substr(0,n)==pref)
                    ans++;
            }
        }
        return ans;
    }
};
