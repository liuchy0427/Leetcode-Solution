/*
 * @lc app=leetcode id=202 lang=swift
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
    private func getNext(_ n: Int) -> Int{
        var sum = 0
        var input = n

        while input > 0{
            let remainder = input % 10
            sum += remainder * remainder
            input /= 10
        }

        return sum
    }
    func isHappy(_ n: Int) -> Bool {
        var input = n
        var seen = Set<Int>()

        while input != 1{
            if seen.contains(input){
                return false
            }
            seen.insert(input)
            input = getNext(input)
        }

        return true
    }
}
// @lc code=end

