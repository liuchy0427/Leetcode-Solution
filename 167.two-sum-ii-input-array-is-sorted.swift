/*
 * @lc app=leetcode id=167 lang=swift
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        var l = 0
        var r = numbers.count - 1
        var sum = 0
        while l < r{
            sum = numbers[l] + numbers[r]
            if(sum == target){
                return [l+1, r+1]
            }
            else if (sum < target){
                l += 1
            }
            else{
                r -= 1
            }
        }
        return []
    }
}
// @lc code=end

