/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(n == 1)  return 1;
        if(m == 1)  return 1;
        vector<vector<int>> dp(m , vector<int>(n, 1));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
// @lc code=end
