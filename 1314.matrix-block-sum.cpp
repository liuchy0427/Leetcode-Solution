/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefix(m,vector<int>(n,0));
        vector<vector<int>> ans(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            int tmp = 0;
            for(int j=0;j<n;j++){
                tmp += mat[i][j];
                prefix[i][j] = tmp;
            }
        }

        for(int i=1;i<m;i++)
            for(int j=0;j<n;j++)
                prefix[i][j] += prefix[i-1][j];
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int rmin = i - k - 1;
                int rmax = min(i + k, m-1);
                int cmin = j - k - 1;
                int cmax = min(j + k, n-1);
                // cout<<rmin<<" "<<rmax<<" "<<cmin<<" "<<cmax<<endl;
                if(rmin < 0 && cmin < 0)
                    ans[i][j] = prefix[rmax][cmax];
                else if(rmin < 0)
                    ans[i][j] = prefix[rmax][cmax] - prefix[rmax][cmin];
                else if(cmin < 0)
                    ans[i][j] = prefix[rmax][cmax] - prefix[rmin][cmax];
                else
                    ans[i][j] = prefix[rmax][cmax] - prefix[rmax][cmin] - prefix[rmin][cmax] + prefix[rmin][cmin];

            }
        }
        return ans;     

    }
};
// @lc code=end

