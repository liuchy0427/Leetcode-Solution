/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        if (n<=0) return 0;
        
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int i=1;i<n+1;i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = min(dp[i], dp[i - j*j]+1);
            }
        }

        return dp.back();
    }
};
// @lc code=end

