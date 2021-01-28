/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    void recursive(vector<vector<int>>& ans,int index, vector<int>& cur, vector<int>& nums){  
        // for(auto x:cur)
        //     cout<<x<<endl;
        ans.push_back(cur);
        if(nums.size() < 1) return;
        for(int i=index;i<nums.size();i++){
            cur.push_back(nums[i]);
            recursive(ans, i+1, cur, nums);
            cur.pop_back();
        }
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        recursive(ans, 0, cur, nums);
       
        return ans;
    }
};
// @lc code=end

