/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> mp;
        vector<TreeNode*> ret;
        for(int i=0;i<to_delete.size();i++)
            mp.insert(to_delete[i]);
        
        dfs(root, mp, ret);
        if(root)
            ret.push_back(root);
        return ret;
    }

    void dfs(TreeNode* &root, set<int> mp, vector<TreeNode*>& ret){
        if(!root) return; 

        dfs(root->left, mp, ret);
        dfs(root->right, mp, ret);

        if(mp.find(root->val) != mp.end()){
            if(root->right){
                ret.push_back(root->right);
            } 
        
            if(root->left){
                ret.push_back(root->left);
            } 
            
            // root->right = nullptr;
            // root->left = nullptr;
            root = NULL;
            delete root;
        }
    }
};
// @lc code=end

