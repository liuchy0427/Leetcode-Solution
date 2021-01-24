/*
 * @lc app=leetcode id=387 lang=swift
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
    func firstUniqChar(_ s: String) -> Int {
        if s.count < 1 { return -1 } 
        var mp = [Character:Int]()

        for (index,char) in s.enumerated(){
            if let i = mp[char]{
                mp[char] = -1
            }else{
                mp[char] = index
            }
        }
        var sorted = mp.sorted{return $0.value < $1.value}
        print(sorted)
        
        for (key, value) in sorted{
            if value != -1{
                return value
            }
        }
        return -1

    }
}
// @lc code=end

