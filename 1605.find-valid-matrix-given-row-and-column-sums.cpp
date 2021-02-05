/*
 * @lc app=leetcode id=1605 lang=cpp
 *
 * [1605] Find Valid Matrix Given Row and Column Sums
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> num(m, vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                num[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= num[i][j];
                colSum[j] -= num[i][j];
            }
        }

        return num;
    }
};
// @lc code=end

