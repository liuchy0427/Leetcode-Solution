/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r){
            while(l < r && nums[l] == nums[l + 1])
                l++;
            while(l < r && nums[r] == nums[r - 1])
                r--;
            
            int mid = l + (r - l)/2;
            cout<<nums[l]<<" "<<nums[mid]<<" "<<nums[l]<<endl;

            if(nums[mid] == target)
                return true;
            
            
            if(nums[mid] > target){
                if(nums[l] > nums[mid] || nums[l] <= target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else{
                if(nums[l] <= nums[mid] || nums[l] > target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return false;
    }
};
// @lc code=end

