/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while(q.size()){
            int n = q.size();
            vector<int> l;

            for(int i=0;i<n;i++){
                auto n = q.front();
                q.pop();

                for(auto c:n->children)
                    q.push(c);
                
                l.push_back(n->val);
            }

            ans.push_back(l);

        }
        return ans;
    }
};
// @lc code=end

