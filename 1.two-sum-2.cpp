/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(int i=0;i<nums.size();i++){
            // for(auto x:mp){
            //     cout<<x.first<<" "<<x.second<<endl;
            // }
            // cout<<"---------------\n";
            if(mp.find(target - nums[i]) != mp.end() && i != mp[target - nums[i]])
                return {i, mp[target - nums[i]]};
            
            mp[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

