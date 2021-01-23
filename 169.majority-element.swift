/*
 * @lc app=leetcode id=169 lang=swift
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        var nums = nums.sorted()

        return nums[nums.count / 2]
    }
}
// @lc code=end

