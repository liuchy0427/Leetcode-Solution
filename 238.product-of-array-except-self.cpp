/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int start = 1;
        int end = 1;
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++)
        {

            // for (auto x : ans)
            // {
            //     cout << x << " ";
            // }

            // cout << "Start-> " << start;
            // cout << " End-> " << end;
            // cout << endl;
            ans[i] *= start;
            start *= nums[i];
            ans[n - 1 - i] *= end;
            end *= nums[n - 1 - i];
        }

        return ans;
    }
};
// @lc code=end
