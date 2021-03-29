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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prePos = 0;
        int inPos = 0;

        return result(preorder, inorder , INT_MIN, prePos, inPos);

        // return helper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

    TreeNode* result(vector<int>& preorder, vector<int>& inorder, int stop, int& prePos, int& inPos){
        cout<<prePos<<" "<<inPos<<endl;
        if(prePos >= preorder.size())
            return nullptr;
        
        if(inorder[inPos] == stop){
            inPos++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[prePos]);
        prePos++;
        root->left = result(preorder, inorder, root->val, prePos, inPos);
        root->right = result(preorder, inorder, stop, prePos, inPos);

        return root;

    }




    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        
        if(ps >= pe)
            return nullptr;

        // cout<<ps<<" "<<pe<<" : "<<is<<" "<<ie<<endl;
        TreeNode *root = new TreeNode(preorder[ps]);

        int pos = 0;

        for(int i=is;i<ie;i++){
            if(inorder[i] == preorder[ps]){
                pos = i;
                break;
            }
        }


        root->left = helper(preorder, inorder, ps + 1, ps + pos - is + 1, is, pos);
        root->right = helper(preorder, inorder, ps + pos - is + 1, pe, pos + 1, ie);

        return root;
    }
};
// @lc code=end

