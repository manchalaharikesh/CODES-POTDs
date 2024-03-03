// DATE: 03-MAR-2024
// Question URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Question: 19. Remove Nth Node From End of List
// Description: Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Approach: 1. Count the position from start, then iterate to a step behind the node then delete it.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func removeNthFromEnd(head *ListNode, n int) *ListNode {
    if head==nil {
        return head;
    }

    var temp, prev *ListNode = head, head;
    var posFromFirst, total int = 0, 0;

    for temp!=nil {
        total++;
        temp=temp.Next;
    }

    posFromFirst = total-n+1;
    if posFromFirst==1 {
        return head.Next;
    }

    temp=head;

    for posFromFirst > 1 {
        prev=temp;
        temp=temp.Next;
        posFromFirst--;
    }

    prev.Next=temp.Next;
    return head;
}