/*
 * @lc app=leetcode id=21 lang=swift
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        // if l1 == nil { return l2 }
        // if l2 == nil { return l1 }
        var l1 = l1
        var l2 = l2
        // var ans:ListNode?

        // if(l1!.val > l2!.val){
        //     ans = l2
        //     ans!.next = mergeTwoLists(l1, l2!.next)
        // }
        // else{
        //     ans = l1
        //     ans!.next = mergeTwoLists(l1!.next, l2)
        // }
        if l1 == nil || l2 != nil && l1!.val > l2!.val {
            swap(&l1, &l2)
        }
        if l1 != nil {
            l1!.next = mergeTwoLists(l1!.next,l2)
        }

        return l1
    }
}
// @lc code=end

