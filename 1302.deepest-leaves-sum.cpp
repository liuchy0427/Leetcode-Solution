/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* cur, int& sum, int depth, int& maxdepth){
        if(!cur) return;

        if(cur->left == nullptr && cur->right == nullptr){
            if(depth == maxdepth)
                sum += cur->val;
            else if(depth > maxdepth){
                maxdepth = depth;
                sum = cur->val;
            }
        }

        helper(cur->left, sum, depth + 1, maxdepth);
        helper(cur->right, sum, depth + 1, maxdepth);

    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        helper(root, sum, 1, 1);
        return sum;
    }
};
// @lc code=end

