// DATE: 07-MAR-2023
// Question URL: https://leetcode.com/problems/middle-of-the-linked-list/description/

// Question: 876. Middle of the Linked List
// Description: Given the head of a singly linked list, return the middle node of the linked list.

//				If there are two middle nodes, return the second middle node.

// Approach: 1. Use slow and fast pointer concept.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func middleNode(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }

    var slow, fast *ListNode = head, head.Next

    for fast.Next != nil && fast.Next.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }

    return slow.Next
}