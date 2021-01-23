/*
 * @lc app=leetcode id=104 lang=swift
 *
 * [104] Maximum Depth of Binary Tree
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
    func recursive(_ node: TreeNode?, _ depth:Int) -> Int{
        guard node != nil else {
            return depth
        }
        return max(recursive(node!.left, depth + 1), recursive(node!.right, depth + 1))
    }
    func maxDepth(_ root: TreeNode?) -> Int {
        if let root = root{
            return recursive(root, 0)
        }else{
            return 0
        }
    }
}
// @lc code=end

