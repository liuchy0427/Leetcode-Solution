/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;

        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* root, int cur){
        
        cur ^= 1 << root->val;
        if(root->left == root->right)
            ans += !(cur & (cur-1));
        if(root->left) dfs(root->left, cur);
        if(root->right) dfs(root->right, cur);

        cur ^= 1 << root->val;
    }
};
// @lc code=end

