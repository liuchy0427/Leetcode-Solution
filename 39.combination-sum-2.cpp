/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
public:
    void recursive(vector<int> &cur, int index, vector<int> candidates, int target, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                cur.push_back(candidates[i]);
                recursive(cur, i, candidates, target - candidates[i], ans);
                // 如果不符合的話 Pop舊的
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> cur;

        recursive(cur, 0, candidates, target, ans);
        return ans;
    }
};
// @lc code=end
