/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int l = depth(root->left);
        int r = depth(root->right);

        if(l == r)
            return root;
        
        return l > r ? subtreeWithAllDeepest(root->left) : subtreeWithAllDeepest(root->right);
         
    }

    int depth(TreeNode* root){
        if(!root) return 0;

        return max(depth(root->left), depth(root->right)) + 1;
    }
};
// @lc code=end

