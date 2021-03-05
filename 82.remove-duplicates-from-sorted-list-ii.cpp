/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
        if(!head || !head->next) return head;
        vector<ListNode* > stk;
        ListNode* tmp = head;

        while(tmp){
            if(!stk.empty() && stk.back()->val == tmp->val){
                while(tmp && tmp->val == stk.back()->val)
                    tmp = tmp->next;
                stk.pop_back();
            }
            else{
                stk.push_back(tmp);
                tmp = tmp->next;
            }

            for(auto s:stk)
                cout<<s->val<<" ";
            cout<<endl;
            
        }

        if(stk.empty()) return nullptr;
        
        for(int i=0;i<stk.size()-1;i++){
            stk[i]->next = stk[i+1];
        }
        stk.back()->next = nullptr;

        return stk[0];
    }
};
// @lc code=end

