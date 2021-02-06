/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
    vector<TreeNode*> arr;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }

    TreeNode* sortArr(int l,int r){
        if(l > r) return nullptr;
        int mid = l + (r-l)/2;
        TreeNode* root = arr[mid];

        root->left = sortArr(l, mid-1);
        root->right = sortArr(mid+1, r);

        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return sortArr(0, arr.size()-1);
    }
};
// @lc code=end

