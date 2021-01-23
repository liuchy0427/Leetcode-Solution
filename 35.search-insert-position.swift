/*
 * @lc app=leetcode id=35 lang=swift
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        var lo = 0
        var hi = nums.count - 1

        while lo <= hi{
            let mid = (lo + hi) / 2
            if(nums[mid] < target){
                lo = mid + 1
            }else{
                hi = mid - 1
            }
        }

        return lo
    }
}
// @lc code=end

