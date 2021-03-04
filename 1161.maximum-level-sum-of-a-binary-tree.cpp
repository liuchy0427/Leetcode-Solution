/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;

        int maxSum = INT_MIN, level = 0, maxLevel;;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            int n = q.size();
            int s = 0;
            
            for(int i=0;i<n;i++){
                auto node = q.front();

                s += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }

            level++;
            if(s > maxSum){
                maxSum = s;
                maxLevel = level;
            }
        }

        return maxLevel;
    }

};
// @lc code=end

