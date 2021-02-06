/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    TreeNode* recursive(TreeNode* root,int val){
        if(root->val < val){
            if(root->right) 
                recursive(root->right, val);
            else
                root->right = new TreeNode(val);
        }else{
            if(root->left)
                recursive(root->left, val);
            else
                root->left = new TreeNode(val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return (new TreeNode(val));
        return recursive(root, val);
    }
};
// @lc code=end

