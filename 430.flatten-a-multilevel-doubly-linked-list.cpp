/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;

        vector<Node* > stk;
        Node *cur = NULL, *pre = NULL, *ret = NULL;
        Node *tmp = head;

        stk.push_back(tmp);
        while(!stk.empty()){
            pre = cur;
            cur = stk.back(); stk.pop_back();

            if(cur->next)   stk.push_back(cur->next);
            if(cur->child)  stk.push_back(cur->child);

            cur->child = NULL;
            cur->prev = pre;
 
            if(pre)
                pre->next = cur;
            
        }

        return head;
    }
};
// @lc code=end

