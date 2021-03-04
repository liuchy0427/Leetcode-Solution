/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 */

// @lc code=start
class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N+1, false);

        for(int i=2;i<=N;i++){
            for(int j=1;j*j<i;j++){
                if(i % j == 0 && !dp[i-j])
                    dp[i] = !dp[i-j];
            }
        }

        return dp[N];
    }
};
// @lc code=end

