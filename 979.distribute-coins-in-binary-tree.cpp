/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
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
    int ans = 0;
public:
    int distributeCoins(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        ans += abs(left) + abs(right);
        return left + right + root->val - 1;
    }
};
// @lc code=end

