/*
 * @lc app=leetcode id=8 lang=swift
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
    func myAtoi(_ s: String) -> Int {
        var s = s.trimmingCharacters(in: .whitespaces)
        var negative = false

        if s.first == "-" {
            negative = true
            s.removeFirst()
        }else if s.first == "+" {
            negative = false
            s.removeFirst()
        }

        var arr = [Character]()
        for c in s{
            if "0123456789".contains(c){
                arr.append(c)
            }else{
                break
            }
        }

        guard var ans = Double(String(arr)) else{
            return 0
        }

        if negative{
            ans *= -1
            return ans < Double(Int32.min) ? Int(Int32.min) : Int(ans)
        }else{
            return ans > Double(Int32.max) ? Int(Int32.max) : Int(ans)
        }
        
    }
}
// @lc code=end

