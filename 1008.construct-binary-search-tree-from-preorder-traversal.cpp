/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
    // TreeNode* recursive(TreeNode* root, int index){
    //     if(!root) return ;
    //     if
    // }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        vector<int> left;
        vector<int> right;

        for(int i=1;i<preorder.size();i++){
            if(preorder[i] > preorder[0])
                right.push_back(preorder[i]);
            else
                left.push_back(preorder[i]);
        }

        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);


        return root;
    }
};
// @lc code=end

