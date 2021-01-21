/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution
{
public:
    // 記得 num 不能 call by referene, 因爲沒有Swap回來, 減少Duplicate
    void dfs(vector<vector<int>> &res, vector<int> nums, int pos)
    {
        if (pos == nums.size() - 1)
        {
            res.push_back(nums);
            return;
        }

        for (int i = pos; i < nums.size(); i++)
        {
            if (i != pos && nums[i] == nums[pos])
            {
                continue;
            }
            swap(nums[pos], nums[i]);
            dfs(res, nums, pos + 1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        dfs(res, nums, 0);
        return res;
    }
};
// @lc code=end
