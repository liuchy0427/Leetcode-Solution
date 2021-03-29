/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* helper(vector<int> preorder, vector<int> inorder, int ps, int pe, int is, int ie){
        if(ps > pe) return nullptr;
        int mid;
        
        TreeNode* node = new TreeNode(preorder[ps]);

        for(int i=is;i<=ie;i++){
            if(inorder[i] == preorder[ps]){
                mid = i;
                break;
            }
        }
        // cout<<mid<<endl;
        node->left = helper(preorder, inorder, ps+1, ps + mid - is, is, mid-1);
        node->right = helper(preorder, inorder, pe - (ie - mid) + 1, pe, mid+1, ie);

        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
// @lc code=end

