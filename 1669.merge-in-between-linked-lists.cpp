/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ans = list1;
        ListNode* head = list1;
        ListNode* tail = list1;

        int count = 0;
        while(list1 != NULL){
            // cout<<count<<" ";
            if(count == a-1)    head = list1;
            if(count == b+1)    tail = list1;
            count++;
            list1 = list1 -> next;
        }
        // cout<<endl;
        // cout<<head->val<<" "<<tail->val<<endl;
        head->next = list2;

        while(list2->next != NULL)
            list2 = list2 -> next;
        list2->next = tail;

        return ans;
    }
};
// @lc code=end

