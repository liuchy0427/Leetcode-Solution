/*
 * @lc app=leetcode id=402 lang=swift
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution {
    func removeKdigits(_ num: String, _ k: Int) -> String {
        if num.count < 1 {return "0"}

        var count = k
        var str = [Character]()
        var arr = Array(num)

        for i in 0..<arr.count{
            while (count > 0 && arr[i+1] > arr[i]) {
                str.removeLast()
                count -= 1
            }

            str.append(arr[i])
        }

        while count > 0{
            str.removeLast()
            count -= 1
        }

        while let first = str.first , first == "0"{
            str.removeFirst()
        }

        return str.isEmpty ? "0" : String(str)
        
        
    }
}
// @lc code=end

