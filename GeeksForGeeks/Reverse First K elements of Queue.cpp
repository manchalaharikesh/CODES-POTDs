// DATE: 12-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
// Question: Reverse First K elements of Queue
// Description: Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

//              Only following standard operations are allowed on queue.

//              enqueue(x) : Add an item x to rear of queue
//              dequeue() : Remove an item from front of queue
//              size() : Returns number of elements in queue.
//              front() : Finds front item.
//              Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.
// Approach: 1. Pop k elements from queue to stack, move elements from stack to queue then move n-k elements from queue front to back.

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;
        int t, n = q.size();
        
        for(int i = 0; i < k; i++){
            t = q.front();
            q.pop();
            s.push(t);
        }
        
        for(int i = 0; i < k; i++){
            t = s.top();
            q.push(t);
            s.pop();
        }
        
        for(int i = 0; i < n - k; i++){
            t = q.front();
            q.push(t);
            q.pop();
        }
        
        return q;
    }
};