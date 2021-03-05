/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre = NULL, *tmp = head;

        while(tmp){
            if(pre && pre->val == tmp->val){
                pre->next = tmp->next;
            } 
            else
                pre = tmp;

            tmp = tmp->next;
        }

        return head;
    }
};
// @lc code=end

