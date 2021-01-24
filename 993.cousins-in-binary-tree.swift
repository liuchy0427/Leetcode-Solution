/*
 * @lc app=leetcode id=993 lang=swift
 *
 * [993] Cousins in Binary Tree
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
    var xDepth = 1
    var yDepth = 1
    var xParent: TreeNode? = nil
    var yParent: TreeNode? = nil

    func isCousins(_ root: TreeNode?, _ x: Int, _ y: Int) -> Bool {
        var depth = 1
        findParentDepth(root, x, y, root, depth)

        if xDepth == yDepth && xParent !== yParent{
            return true
        }

        return false
    }


    func findParentDepth(_ root:TreeNode?, _ x:Int, _ y:Int, _ parent: TreeNode?, _ depth:Int){
        guard let root = root else {
            return 
        }

        if root.val == x{
            xDepth = depth
            xParent = parent
        }
        if root.val == y{
            yDepth = depth
            yParent = parent
        }

        findParentDepth(root.left, x, y, root, depth + 1)
        findParentDepth(root.right, x, y, root, depth + 1)
    }
}
// @lc code=end

