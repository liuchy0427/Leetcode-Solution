/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0 && j>0 && matrix[i][j] != 0)
                    matrix[i][j] = min(matrix[i-1][j], min(matrix[i][j-1], matrix[i-1][j-1])) + 1;
                
                ans += matrix[i][j];
            }
        }

        return ans;
    }
};
// @lc code=end

