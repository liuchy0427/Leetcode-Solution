/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
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
    TreeNode* ans;
    int maxDepth = -1;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return nullptr;
        int l = depth(root->left);
        int r = depth(root->right);

        if(l == r)
            return root;
        
        return l > r ? lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);




        // if(!root || (!root->left && !root->right)) return root;
        // dfs(root, nullptr, 0);
        // return ans;
    }

    int depth(TreeNode* root){
        if(!root) return 0;
        else{
            int l = depth(root->left);
            int r = depth(root->right);

            return max(l,r)+1;
        }
    }


    void dfs(TreeNode* root, TreeNode* pre,int depth){
        // cout<<root->val<<" "<<depth<<" "<<maxDepth<<endl;

        if(!root->left && !root->right && depth > maxDepth){
            maxDepth = depth;
            ans = pre;
        }

        if(root->left) dfs(root->left, root, depth+1);
        if(root->right) dfs(root->right, root, depth+1);
    }
};
// @lc code=end

