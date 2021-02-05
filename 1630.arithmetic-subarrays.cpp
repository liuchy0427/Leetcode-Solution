/*
 * @lc app=leetcode id=1630 lang=cpp
 *
 * [1630] Arithmetic Subarrays
 */

// @lc code=start
class Solution {
public:
    vector<bool> ans;
    bool helper(vector<int> n){
        if(n.size() < 2) return false;
        // for(auto x:n)
        //     cout<<x<<" ";
        // cout<<endl;
        sort(n.begin(), n.end());

    

        int dif = n[1] - n[0];
        for(int i=2;i<n.size();i++){
            if(n[i] - n[i-1] != dif)
                return false;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        for(int i=0;i<l.size();i++)
            ans.push_back(helper(vector<int>(nums.begin()+l[i], nums.begin()+r[i]+1)));

        return ans;
    }
};
// @lc code=end

