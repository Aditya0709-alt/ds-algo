class Solution {
public:
    int search(vector<int> a, int target, bool findStartIndex)
    {
        int ans = -1;
        int start = 0, end = a.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (target < a[mid])
            {
                end = mid - 1;
            }
            else if (target > a[mid])
            {
                start = mid + 1;
            }
            else
            {
                ans = mid;
                if (findStartIndex)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans{-1, -1};
        ans[0] = search(nums, target, true);

        if (ans[0] != -1)
        {
            ans[1] = search(nums, target, false);
        }
        return ans;
    }
};
