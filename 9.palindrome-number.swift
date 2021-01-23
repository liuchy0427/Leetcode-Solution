/*
 * @lc app=leetcode id=9 lang=swift
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
    func isPalindrome(_ x: Int) -> Bool {
        var num = x        
        var reverse = 0
        var mod = 10

        if num < 0{
            return false
        }

        while num != 0{
            reverse *= 10
            reverse += (num % mod)
            num /= mod
        }
        print(reverse, x)
        
        return (reverse == x) 
    }
}
// @lc code=end

