/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
public:

    void recursize(vector<int>& candidates, vector<int> cur, int index, int target){
        if(target == 0)
            ans.push_back(cur);

        if(index >= candidates.size() || target < candidates[index])
            return;
        

        int num = candidates[index++];
        cur.push_back(num);
        recursize(candidates, cur, index, target - num);
        cur.pop_back();

        while(index < candidates.size() && num == candidates[index])
            index++;

        recursize(candidates, cur, index, target);
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        recursize(candidates, {}, 0 , target);
        
        return ans;
    }
};
// @lc code=end

