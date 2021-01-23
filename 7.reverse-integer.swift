/*
 * @lc app=leetcode id=7 lang=swift
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
    func reverse(_ x: Int) -> Int {
        var x = x
        var ans = 0
        var mod = 10
        
        while x != 0{
            ans *= 10
            ans += x % 10
            x /= 10
        }

        if ans > Int(Int32.max) || ans < Int(Int32.min){
            return 0
        }
            

        return ans;
    }
}
// @lc code=end

