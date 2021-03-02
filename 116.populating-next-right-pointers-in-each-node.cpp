/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // if(!root) return nullptr;
        // bfs(root);
        // return root;
        Node* ret = root;
        while(root && root->left){
            Node* next = root->left;
            while(root){
                root->left->next = root->right;
                if(root->next)
                    root->right->next = root->next->left;
                else
                    root->right->next = nullptr;
                
                root = root->next;
            }
            root = next;

        }
        return ret;
    }

    // void bfs(Node* root){
    //     queue<Node*> q;
    //     q.push(root);
    //     int depth = 0;
    //     int count = 1;
    //     // cout<<pow(2,depth)<<endl;
    //     while(!q.empty()){
    //         Node* n = q.front();
    //         q.pop();
    //         if(count < pow(2,depth)){
    //             count++;
    //             n->next = q.front();
    //         }
    //         else{
    //             count = 1;
    //             n->next = nullptr;
    //             depth++;
    //         }    
    //         if(n->left) q.push(n->left);
    //         if(n->right) q.push(n->right);        
    //     }
    // }
};
// @lc code=end

