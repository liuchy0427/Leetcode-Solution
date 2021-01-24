/*
 * @lc app=leetcode id=11 lang=swift
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var ans = 0

        var l = 0
        var r = height.count - 1

        while l < r{
            ans = max(ans, min(height[l], height[r]) * (r - l))

            if (height[l] > height[r]){
                r -= 1
            }else{
                l += 1
            }
        }

        return ans;
        
    }
}
// @lc code=end

