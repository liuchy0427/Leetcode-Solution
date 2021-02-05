/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
    TreeNode* clone(TreeNode* root){
        TreeNode* newRoot = new TreeNode(0);
        newRoot->left = (root->left) ? clone(root->left) : nullptr;
        newRoot->right = (root->right) ? clone(root->right) : nullptr;

        return newRoot;
    }

    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0) return {};
        if(N == 1) return {new TreeNode(0)};

        vector<TreeNode*> ans;

        for(int i=2;i<N;i+=2){
            auto left = allPossibleFBT(i-1);
            auto right = allPossibleFBT(N-i);

            for(int l=0;l<left.size();l++){
                for(int r=0;r<right.size();r++){
                    ans.push_back(new TreeNode(0));

                    ans.back()->left = (r == right.size()-1) ? left[l] : clone(left[l]);
                    ans.back()->right = (l == left.size()-1) ? right[r] : clone(right[r]);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

