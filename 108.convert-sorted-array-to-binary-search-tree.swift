/*
 * @lc app=leetcode id=108 lang=swift
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func sortedArrayToBST(_ nums: [Int]) -> TreeNode? {
        if nums.count == 0 {
            return nil
        }

        return recursive(nums, 0, nums.count - 1)
    }

    func recursive(_ nums: [Int], _ left: Int, _ right: Int) -> TreeNode?{
        if(left > right)   {return nil}

        let mid = left + (right - left) / 2
        let tnode = TreeNode(nums[mid])

        tnode.left = recursive(nums, left, mid - 1)
        tnode.right = recursive(nums, mid + 1, right)

        return tnode
    }
}
// @lc code=end

