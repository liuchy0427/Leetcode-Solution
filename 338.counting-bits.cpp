/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);

        for(int i=1;i<=num;i++)
            ans[i] = ans[i & (i-1)] + 1;
    
        return ans;
    }
};
// @lc code=end

