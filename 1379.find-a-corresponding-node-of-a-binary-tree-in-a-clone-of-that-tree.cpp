/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == nullptr) return nullptr;
        else if(original == target) return cloned;
        else
            return getTargetCopy(original->left, cloned->left, target) ? : getTargetCopy(original->right, cloned->right,target);
    }
};
// @lc code=end

