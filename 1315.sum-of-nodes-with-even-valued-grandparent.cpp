/*
 * @lc app=leetcode id=1315 lang=cpp
 *
 * [1315] Sum of Nodes with Even-Valued Grandparent
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
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root, null, null);
    }

    int helper(TreeNode* cur, TreeNode* parent, TreeNode* grandparent){
        int sum = 0;
        if(!cur)
            return 0;
        if(grandparent && grandparent->val %2 = 0){
            sum += cur->val;
        }

        sum += helper(cur->left, cur, parent);
        sum += helper(cur->right, cur, parent);

        return sum;
    }
};
// @lc code=end

