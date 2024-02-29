// DATE: 29-FEB-2024
// Question URL: https://leetcode.com/problems/even-odd-tree/description/

// Question: 1609. Even Odd Tree
// Description: A binary tree is named Even-Odd if it meets the following conditions:

//				The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
//				For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
//				For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
//				Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.
// Approach: 1. Brute Force have an inorder traversal and store latest data vals in a map for each depth, compare and return answers accordingly.

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func inOrder(root *TreeNode, d int, m map[int]int) bool {
    if root == nil {
        return true
    }
    if d % 2 == root.Val % 2 {
        return false
    }

    _, ok := m[d]

    if ok {
        if d % 2 == 0 {
            if m[d] < root.Val {
                m[d] = root.Val
            } else {
                return false
            }
        } else if d % 2 != 0 {
            if m[d] > root.Val {
                m[d] = root.Val
            } else {
                return false
            }
        }
    } else {
        m[d] = root.Val
    }

    return inOrder(root.Left, d+1, m) && inOrder(root.Right, d+1, m)
}

func isEvenOddTree(root *TreeNode) bool {
    m := make(map[int]int)

    return inOrder(root, 0, m)
}