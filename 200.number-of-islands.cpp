/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<int> offsets = {0, 1, 0, -1, 0};

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j] == '1'){
        //             ans++;
        //             dfs(i, j, m, n, grid);
        //         }
        //     }
        // }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    grid[i][j] = '0';  
                    queue<pair<int,int>> q;
                    q.push({i,j});

                    while(!q.empty()){
                        pair<int,int> p = q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int r = p.first + offsets[k], c = p.second + offsets[k+1];
                            if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == '1'){
                                grid[r][c] = '0';
                                q.push({r,c});
                            } 
                        }
                    }

                }
            }
        }
        return ans;
    }

    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid){
        // cout<<i<<":"<<j<<endl;
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j] == '1'){
            grid[i][j] = '0';

            dfs(i+1,j,m,n,grid);
            dfs(i-1,j,m,n,grid);
            dfs(i,j+1,m,n,grid);
            dfs(i,j-1,m,n,grid);
        }
        else
            return;
    }
};
// @lc code=end

