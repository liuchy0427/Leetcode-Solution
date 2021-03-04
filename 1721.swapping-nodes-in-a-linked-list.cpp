/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode *k1,*k2;
        ListNode *tmp = head;

        int len = 0;
        while(tmp){
            len++;
            tmp = tmp->next;
        }

        cout<<len<<endl;
        tmp = head;
        int count = 0;

        while(tmp){
            count++;
            if(count == k)
                k1 = tmp;
            if(count == len - k+1)
                k2 = tmp;
            tmp = tmp->next;
        }
        
        int x = k1->val;
        k1->val = k2->val;
        k2->val = x;



        return head;

    }
};
// @lc code=end

