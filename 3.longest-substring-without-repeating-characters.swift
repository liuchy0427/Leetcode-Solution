/*
 * @lc app=leetcode id=3 lang=swift
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        guard s.count > 1 else { return s.count }
        var mp = [Character : Int]()
        var l = 0
        var r = 0
        var ans = 0;

        for char in s{
            if let index = mp[char]{
                ans = max(ans, r - l)
                l = max(l, index + 1)
            }
            mp[char] = r
            r += 1
        }

        return max(ans, r - l)
        
    
    }
}
// @lc code=end

