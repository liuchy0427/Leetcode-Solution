/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
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
    int numComponents(ListNode* head, vector<int>& g) {
        // sort(g.begin(), g.end());
        unordered_set<int> mp;
        for(int i=0;i<g.size();i++)
            mp.insert(g[i]);

        int index = 0;
        int ans = 0;
        bool connect = false;
        while(head){
            if(mp.count(head->val)){
                if(!connect)
                    ans++;
                connect = true;
            }
            else
                connect = false;

            head = head->next;
        }

        return ans;
    }
};
// @lc code=end

