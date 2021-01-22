/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* recursive(ListNode* head, ListNode* last,int k , int len){
        
        tmp->next = head;
        pre->next = NULL;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
        int len =  1;
        ListNode *tmp = head;
        ListNode *pre = head;

        while(tmp -> next){
            pre = tmp;
            tmp = tmp -> next;
            len++;
        }

        k %= len;
        if (k == 0) return head;

        cout<<pre->val<<endl;
        cout<<tmp->val<<endl;
        cout<<"======"<<endl;
            
        

        return recursive(tmp,pre, --k,len);
    }
};
// @lc code=end

