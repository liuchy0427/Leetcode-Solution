/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;

        return helper(inorder, postorder, 0, inorder.size(), 0 , postorder.size());
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe){
        if(ps >= pe || is >= ie)
            return nullptr;
        // cout<<is<<" "<<ie<<" : "<<ps<<" "<<pe<<endl;

        int pos = mp[postorder[pe-1]];

        TreeNode* root = new TreeNode(inorder[pos]);

        root -> right = helper(inorder, postorder, pos + 1, ie, pe - (ie - pos), pe-1);
        root -> left = helper(inorder, postorder, is, pos, ps, ps + (pos - is));

        return root;
       
    }
};
// @lc code=end

