/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
    int res = 0;
public:
    void dfs(int x, int y, vector<vector<int>>& grid, int zeros){
        // cout<<x<<" "<<y<<" "<<zeros<<endl;
        if(x<0 || y<0 || x>=grid.size() || y >= grid[0].size())
            return;
        
        if(grid[x][y]){
            res += grid[x][y]==2 && !zeros;
            return;
        }

        grid[x][y] = -1;
        zeros--;

        dfs(x, y+1, grid, zeros);
        dfs(x, y-1, grid, zeros);
        dfs(x+1, y, grid, zeros);
        dfs(x-1, y, grid, zeros);

        grid[x][y] = 0;
        zeros++;

    }




    int uniquePathsIII(vector<vector<int>>& grid) {
        int x=0,y=0;
        int zeros = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
                if(!grid[i][j])
                    zeros++;
            }
        }

        // grid[x][y] = -1;
        dfs(x, y+1, grid, zeros);
        dfs(x, y-1, grid, zeros);
        dfs(x+1, y, grid, zeros);
        dfs(x-1, y, grid, zeros);

        return res;
    }
};
// @lc code=end

