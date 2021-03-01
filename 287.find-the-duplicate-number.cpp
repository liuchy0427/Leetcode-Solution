/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(), nums.end());

        // for(int i=1;i<nums.size();i++){
        //     if(nums[i] == nums[i-1])
        //         return nums[i];
        // }

        // for(int i=0;i<nums.size();i++){
        //     int index = abs(nums[i]) - 1;

        //     nums[index] *= -1;
        //     if(nums[index] > 0)
        //         return abs(nums[i]);

        // }
        int hare = nums[0], tortoise = nums[0];

        do{
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }while(hare != tortoise);

        tortoise = nums[0];
        while(hare != tortoise){
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        return hare;
    }
};
// @lc code=end

