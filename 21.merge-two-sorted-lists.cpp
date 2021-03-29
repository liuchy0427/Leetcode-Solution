/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // if(!l1 || l2 && l1->val > l2->val)
        //     swap(l1,l2);

        // if(l1) l1->next = mergeTwoLists(l1->next, l2);
        // return l1;

        ListNode dummy(0);
        ListNode *tail = &dummy;

        while(l1 && l2){
            ListNode *&node=  l1->val < l2->val ? l1 : l2;
            tail = tail->next = node;
            node = node->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;

        // ListNode dummy(0);
        // ListNode *tail = &dummy;
        // while(l1 && l2) {
        //     ListNode *& node = l1->val < l2->val ? l1 : l2;
        //     tail = tail->next = node;
        //     node = node->next;
        // }
        // tail->next = l1 ? l1 : l2;
        // return dummy.next;
    }
};
// @lc code=end

