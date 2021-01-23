/*
 * @lc app=leetcode id=2 lang=swift
 *
 * [2] Add Two Numbers
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
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var l1 = l1
        var l2 = l2
        var prev = ListNode(0)
        var carry = 0
        let head = prev

        while l1 != nil || l2 != nil || carry != 0{
            let cur = ListNode(0)
            let sum = (l2 == nil ? 0 : l2!.val) + (l1 == nil ? 0 : l1!.val) + carry
            cur.val = sum % 10
            carry = sum / 10
            prev.next = cur
            prev = cur
            l1 = (l1 == nil) ? l1 : l1?.next
            l2 = (l2 == nil) ? l2 : l2?.next
        }

        return head.next
    }
}
// @lc code=end

