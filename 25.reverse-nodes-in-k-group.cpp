/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;

        ListNode *ans = new ListNode(0, head);
        ListNode *tmp = head, *pre = ans;

        int len = 0;
        while (tmp)
        {
            tmp = tmp->next;
            len++;
        }

        // cout << len << endl;
        for (int i = 0; i < len / k; i++)
        {
            for (int j = 1; j < k; j++)
            {
                tmp = pre->next;
                pre->next = head->next;
                head->next = head->next->next;
                pre->next->next = tmp;
            }

            pre = head;
            head = head->next;
        }

        return ans->next;
    }
};
// @lc code=end
