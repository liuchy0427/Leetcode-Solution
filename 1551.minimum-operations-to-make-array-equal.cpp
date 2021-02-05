/*
 * @lc app=leetcode id=1551 lang=cpp
 *
 * [1551] Minimum Operations to Make Array Equal
 */

// @lc code=start
class Solution {
public:
    int minOperations(int n) {
        int k = n/2;
        if(n % 2 == 0){
            return (k * k);
        }
        return (k * (k+1));

        
    }
};
// @lc code=end


1 3 5 7 
2 3 5 6 
3 3 5 5 
4 3 5 4 
4 4 4 4 