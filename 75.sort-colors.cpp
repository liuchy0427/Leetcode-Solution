/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // return sort(nums.begin(), nums.end());

        int i = 0, j = 0, k = nums.size() - 1;

        while(j <= k){
            cout<<nums[j]<<endl;
            if(nums[j] == 0) 
                swap(nums[j++], nums[i++]);
            else if(nums[j] == 2)
                swap(nums[j], nums[k--]);
            else 
                j++;
        }
    }
};
// @lc code=end

