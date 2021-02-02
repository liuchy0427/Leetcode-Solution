/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* helper(int i, int j, vector<int> nums){
        if(i <= j){
            auto max_ = max_element(nums.begin()+i,nums.begin()+j+1);
            int max_index = max_ - nums.begin();

            TreeNode* root = new TreeNode(*max_);

            root->left = helper(i, max_index - 1, nums);
            root->right = helper(max_index + 1, j, nums);

            return root;
        }
        else
            return nullptr;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(0, nums.size()-1, nums);
    }
};
// @lc code=end

