/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
    int ans = -1;
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, INT_MIN, INT_MAX);
    
        return ans;
    }

    void dfs(TreeNode* root,int _max, int _min){ 
        _max = max(_max, root->val);
        _min = min(_min, root->val);

        if(root->left == root->right){
            ans = max(ans, _max - _min);
        }

        if (root->left) dfs(root->left, _max, _min);
        if (root->right) dfs(root->right, _max, _min);
    }
};
// @lc code=end

