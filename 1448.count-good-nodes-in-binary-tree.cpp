/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int goodNodes(TreeNode* root) {
        if(!root)   return 0;
        
        helper(root, INT_MIN);
        return ans;
    }

    void helper(TreeNode* root, int _max){
        if(!root)   return;
        
        // cout<<root->val<<" "<<q.top()<<endl;
        if(root->val >= _max)
            ans++;
        
        helper(root->left, max(_max, root->val));
        helper(root->right, max(_max, root->val));
    }
};
// @lc code=end

