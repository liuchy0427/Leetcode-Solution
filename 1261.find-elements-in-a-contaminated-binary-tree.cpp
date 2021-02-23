/*
 * @lc app=leetcode id=1261 lang=cpp
 *
 * [1261] Find Elements in a Contaminated Binary Tree
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
class FindElements {
    unordered_map<int,int> mp;
public:
    FindElements(TreeNode* root) {
        recursive(root, 0);
    }
    
    bool find(int target) {
        // for(auto x:mp)
        //     cout<<x.first<<endl;
        if(mp.find(target) != mp.end())
            return true;
        else
            return false;
    }

    void recursive(TreeNode* root, int val){
        if(!root) return;

        root->val = val;
        mp[root->val]++;
        
        recursive(root->left, 2 * val + 1);
        recursive(root->right, 2 * val + 2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

