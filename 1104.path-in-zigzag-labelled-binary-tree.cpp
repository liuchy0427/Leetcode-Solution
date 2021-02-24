/*
 * @lc app=leetcode id=1104 lang=cpp
 *
 * [1104] Path In Zigzag Labelled Binary Tree
 */

// @lc code=start
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = log(label) / log(2) + 1;

        vector<int> path(level);

        while(label){
            path[level - 1] = label;
            label = pow(2, level) - 1 - label + pow(2, level - 1);
            label >>= 2;
            level--;
        }

        return path;
    }
};
// @lc code=end

