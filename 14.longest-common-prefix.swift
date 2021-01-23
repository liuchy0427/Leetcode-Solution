/*
 * @lc app=leetcode id=14 lang=swift
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        if strs.isEmpty {return ""}
        if strs.count == 1 {return strs[0]}

        let strs = strs.sorted()
        var ans = ""
        // strs = strs.sorted()

        for (char1, char2) in zip (strs.first!, strs.last!){
            if char1 == char2{
                ans += String(char1)
            }
            else{
                break
            }
        }
        return ans
    
    }
}
// @lc code=end

