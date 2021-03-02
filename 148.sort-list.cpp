/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        int len = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur->next;
            len++;
        }
        // cout<<len<<endl;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *left, *right, *tail;

        for(int step=1; step<len; step <<= 1){
            cur = dummy->next;
            tail = dummy;

            while(cur){
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }

        return dummy->next;
        
    }

private:
    ListNode* split(ListNode* head, int n){
        for(int i=1;head && i<n ;i++)
            head = head->next;
        
        if(!head) return nullptr;
        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }

    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
        ListNode* cur = head;
        while(l1 && l2){
            if(l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
            }else{
                cur->next = l1;
                l1 = l1->next;
            }

            cur = cur->next;
        }

        cur->next = l1 ? l1 : l2;
        while(cur->next)    cur = cur->next;
        return cur;
    }
};
// @lc code=end

