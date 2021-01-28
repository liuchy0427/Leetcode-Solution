/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool recursive(vector<vector<char>>& board, string word, int i, int j){
        // cout<<word<<endl;
        if(!word.size())
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if(board[i][j] != word[0])
            return false;
        
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);

        bool ret = recursive(board, s, i+1, j) || recursive(board, s, i-1, j) || recursive(board, s, i, j+1) || recursive(board, s, i, j-1);
        board[i][j] = c;
            
        return ret;  
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){    
                if(recursive(board, word, i, j))
                    return true;
                cout<<"==============="<<endl;
            }
        }
        
        
        return false;
    }
};
// @lc code=end

