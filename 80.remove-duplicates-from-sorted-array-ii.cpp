/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i=2;i<n;i++){
            for(auto x: nums)
                cout<<x<<" ";
            cout<<endl;
            cout<<i<<" "<<i - 2 - count<<" "<<i - count<<endl;
            if(nums[i] == nums[i - 2 - count])
                count++;
            else
                nums[i - count] = nums[i];
        }

        return n - count;
    }
};
// @lc code=end

