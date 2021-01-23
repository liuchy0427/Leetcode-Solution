/*
 * @lc app=leetcode id=206 lang=swift
 *
 * [206] Reverse Linked List
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
    private func recursive(_ first: ListNode?, _ second: ListNode?) -> ListNode?{
        guard let second = second else {
            return first
        }
        let tmp = second.next
        second.next = first

        return recursive(second, tmp)
    }

    func reverseList(_ head: ListNode?) -> ListNode? {
        guard let head = head else{
            return nil
        }
        let second = head.next
        head.next = nil

        return recursive(head, second)
        
    }
}
// @lc code=end

