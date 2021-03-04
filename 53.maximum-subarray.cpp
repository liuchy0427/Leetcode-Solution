/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i=1;i<n;i++){
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            ans = max(dp[i], ans);
        }

        return ans;
    }
};
// @lc code=end

