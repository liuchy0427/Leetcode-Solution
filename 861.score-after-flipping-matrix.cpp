/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();

        int ans = (1 << (n-1)) * m;

        for(int i=0;i<m;i++){
            if(a[i][0] != 1){
                for(int j=0;j<n;j++){
                    a[i][j] = !a[i][j];
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<< " ";
            }
            cout<<endl;
        }

        int i,j;
        for(int j=1;j<n;j++){
            int count = 0;
            for(int i=0;i<m;i++)
                if(a[i][j] == 1)
                    count++;
            
            count = max(count, m - count);
            ans += (1 << (n - 1 - j)) * count;
        }

        return ans;
    }
};
// @lc code=end

