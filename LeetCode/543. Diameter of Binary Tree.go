// DATE: 27-FEB-2024
// Question URL: https://leetcode.com/problems/diameter-of-binary-tree/description/

// Question: 543. Diameter of Binary Tree
// Description: Given the root of a binary tree, return the length of the diameter of the tree.

//              The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

//              The length of a path between two nodes is represented by the number of edges between them.
// Approach: 1. Inorder Traversal to find the max left depth and right depth for each node, and diameter is sum of max(leftDepth + rightDepth) of each node.

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func traverse(root *TreeNode, ans int) (int, int) {
    if root == nil {
        return 0, 0
    }

    left, _ans1 := traverse(root.Left, ans)
    right, _ans2 := traverse(root.Right, ans)

    ans = max(_ans1, _ans2)

    if ans < left + right {
        ans = left + right
    }

    return max(left, right) + 1, ans
}

func diameterOfBinaryTree(root *TreeNode) int {
    _, ans := traverse(root, 0)
    return ans
}