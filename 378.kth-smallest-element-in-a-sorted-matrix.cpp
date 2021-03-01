/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int l = matrix[0][0];
        int r = matrix[n-1][n-1];

        while(l<r){
            int mid = l + (r - l) / 2;

            int count = 0;
            for(int i=0;i<n;i++){
                vector<int>& row = matrix[i];
                count += std::upper_bound(row.begin(), row.end(), mid) - row.begin();
            }

            if(count < k)
                l = mid + 1;
            else 
                r = mid;
        }

        return l;

        
    }
};
// @lc code=end

