/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
public:
    void recursive(vector<int>& candidates, vector<int> cur, int index, int target){
        if(target == 0)
            ans.push_back(cur);

        if(index >= candidates.size() || candidates[index] > target)
            return;

        int num = candidates[index];
        cur.push_back(num);
        recursive(candidates, cur, index, target - num);
        cur.pop_back();

        recursive(candidates, cur, index+1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        recursive(candidates, {}, 0, target);
        return ans;
    }
};
// @lc code=end

