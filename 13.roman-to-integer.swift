/*
 * @lc app=leetcode id=13 lang=swift
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
    func romanToInt(_ s: String) -> Int {
        var mp: [String:Int] = [:]
        var chars = [Character](s)
        var pre = Int(Int32.max)
        var ans = 0

        mp["I"] = 1
        mp["V"] = 5
        mp["X"] = 10
        mp["L"] = 50
        mp["C"] = 100
        mp["D"] = 500
        mp["M"] = 1000

        chars.forEach{(char) in 
            print(ans)
            if let val = mp[String(char)]{
                if val <= pre{
                    ans += val
                }
                else{
                    ans += (val - pre)
                    ans -= pre
                }
                pre = val
            }
        }

        return ans
    }
}
// @lc code=end

