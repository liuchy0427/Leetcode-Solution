/*
 * @lc app=leetcode id=807 lang=cpp
 *
 * [807] Max Increase to Keep City Skyline
 */

// @lc code=start
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row(n,0);
        vector<int> col(n,0);

        int ans = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }


         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans += min(row[i], col[j]) - grid[i][j];
            }
        }

        return ans;
    }
};
// @lc code=end

