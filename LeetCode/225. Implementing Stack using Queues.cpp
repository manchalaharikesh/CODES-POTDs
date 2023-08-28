// DATE: 28-AUG-2023
// Question URL: https://leetcode.com/problems/implement-stack-using-queues/description/

// Question: 225. Implementing Stack using Queues.
// Description: Complete given code snippets such that it performs Stack using Queue Data Structure.
// Approach: 1. Using Deque.

class MyStack {
public:
    deque<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push_back(x);
    }
    
    int pop() {
        int x = q.back();
        q.pop_back();
        return x;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};