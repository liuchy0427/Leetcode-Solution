/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<mat[0].size();i++){
            int r = 0, c = i;
            while(r < mat.size() && c < mat[0].size())
                pq.push(mat[r++][c++]);
            
            
            r = 0, c = i;
            while(!pq.empty()){
                mat[r++][c++] = pq.top();
                pq.pop();
            }
        }

        for(int i=1; i<mat.size();i++){
            int r = i, c = 0;
            while(r < mat.size() && c < mat[0].size())
                pq.push(mat[r++][c++]);
            
            r = i, c = 0;
            while(!pq.empty()){
                mat[r++][c++] = pq.top();
                pq.pop();
            }
        }

        return mat;
    }
};
// @lc code=end

