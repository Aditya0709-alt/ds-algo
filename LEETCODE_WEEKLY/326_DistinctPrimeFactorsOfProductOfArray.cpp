class Solution {
public:
    void count_prime(int &num, int *freq, int &ans)
    {
        for(int i=2; i*i<=num; i++)
        {
            while(num % i == 0)
            {
                num /= i;
                if(freq[i] == 0)
                    ans++;
                freq[i] += 1;
            }
        }
        if(num != 1)
        {
            if(freq[num] == 0)
                ans++;
            freq[num] += 1;
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int freq[1001] = {}, ans = 0;
        for(int num : nums)
        {
            count_prime(num, freq, ans);
        }
        return ans;
    }
};
