// DATE: 28-FEB-2024
// Question URL: https://leetcode.com/problems/find-bottom-left-tree-value/description/

// Question: 513. Find Bottom Left Tree Value
// Description: Given the root of a binary tree, return the leftmost value in the last row of the tree.
// Approach: 1. Hold ans_depth and curr_depth, inorder traversal when ans_depth < curr_depth have ans_val = root.Val.

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func inorder(root *TreeNode, curr_dep int, ans_val *int, ans_dep *int) {
    if root == nil {
        return
    }

    inorder(root.Left, curr_dep+1, ans_val, ans_dep)

    if *ans_dep < curr_dep {
        *ans_val = root.Val
        *ans_dep = curr_dep
    }

    inorder(root.Right, curr_dep+1, ans_val, ans_dep)

    if *ans_dep < curr_dep {
        *ans_val = root.Val
        *ans_dep = curr_dep
    }
}

func findBottomLeftValue(root *TreeNode) int {
    var ans_val, ans_dep int = -1, -1

    inorder(root, 0, &ans_val, &ans_dep)
    return ans_val
}