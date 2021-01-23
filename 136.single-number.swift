/*
 * @lc app=leetcode id=136 lang=swift
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        var ans = 0

        for n in nums{
            ans ^= n
        }

        return ans
    }
}
// @lc code=end

