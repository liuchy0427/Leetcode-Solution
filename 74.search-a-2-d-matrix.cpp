/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0] || target > matrix[matrix.size()-1][matrix[0].size()-1])
            return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m * n - 1;

        while(l <= r){
            int mid = l + (r-l)/2;
            int num = matrix[mid / n][mid % n];

            if(num == target)
                return true;
            else if(num > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;      
    }
};
// @lc code=end

