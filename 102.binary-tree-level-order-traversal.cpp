/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return ans;
        // vector<int> tmp;
        bfs(root);
        return ans;
    }

    // void bfs(TreeNode* root, vector<int>& cur, int depth){
    //     if(!root)  return;
    //     // cout<<root->val<<","<<depth<<endl;
    //     if(depth == 0 || depth > ans.size()-1){
    //         ans.push_back({root->val});
    //         // vector<int> tmp;
    //         // tmp.push_back(root->val);
    //         // ans.push_back(tmp);
    //     }
    //     else{
    //         ans[depth].push_back(root->val);
    //     }

    //     bfs(root->left, cur, depth+1);
    //     bfs(root->right, cur, depth+1);
    // }

    void bfs(TreeNode* root){
        
        queue<TreeNode*> q;
        q.push(root);

        int count = 1;
        vector<int> row;
        while(!q.empty()){
            if(q.front()->left) 
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);

            row.push_back(q.front()->val);
            q.pop();

            if(--count == 0){
                ans.push_back(row);
                row = {};
                count = q.size();
            }
        }
    }
};
// @lc code=end

