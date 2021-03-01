/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> tmp = board;
        
        for(int i=0;i<tmp.size();i++){
            for(int j=0;j<tmp[0].size();j++){
                if(tmp[i][j] == 1)
                    board[i][j] = live(i, j, tmp);
                else
                    board[i][j] = die(i, j, tmp);
            }
        }
    }

    int live(int index1, int index2, vector<vector<int>>& board){
        int count = 0;
        int m = board.size();
        int n = board[0].size();
        
        for(int i = max(0, index1-1);i<min(m,index1+2);i++){
            for(int j=max(0, index2-1);j<min(n,index2+2);j++)
                count += board[i][j];
        }

        if(count < 3)
            return 0;
        else if(count <= 4)
            return 1;
        else
            return 0;
    }

    int die(int index1, int index2, vector<vector<int>>& board){
        int count = 0;
        int m = board.size();
        int n = board[0].size();
        
        for(int i = max(0, index1-1);i<min(m,index1+2);i++){
            for(int j=max(0, index2-1);j<min(n,index2+2);j++)
                count += board[i][j];
        }

        if(count == 3)
            return 1;
        return 0;
    }
};
// @lc code=end

