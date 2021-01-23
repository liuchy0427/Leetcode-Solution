/*
 * @lc app=leetcode id=70 lang=swift
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
    func climbStairs(_ n: Int) -> Int {
        if n < 3{
            return n
        }

        var queue: [Int] = [1, 2]

        for _ in (3...n){
            print(queue)
            
            let dequereValue = queue.removeFirst()
            queue.append(dequereValue + queue.first!)
        }
        
        return queue.last!
    }
}
// @lc code=end

