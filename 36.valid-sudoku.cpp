/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        map<char, int> row[9], col[9], sqr[9];

        char c;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                c = board[i][j];
                if (c != '.')
                {
                    if (++row[i][c] > 1 || ++col[j][c] > 1 || ++sqr[i / 3 * 3 + j / 3][c] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
