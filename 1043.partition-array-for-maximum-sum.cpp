/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int K) {
        int n = arr.size();

        vector<int> dp(n+1, 0);

        for(int i=1;i<=n;i++){
            int best = 0, curMax = 0;
            
            for(int k=1;k<=K && i-k >= 0;k++){
                curMax = max(curMax, arr[i-k]);
                best = max(best, dp[i-k] + curMax * k);
            }
            dp[i] = best;
        }

        return dp[n];
    }
};
// @lc code=end

