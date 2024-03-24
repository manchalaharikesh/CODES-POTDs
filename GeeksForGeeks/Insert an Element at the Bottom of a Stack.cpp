// DATE: 24-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1
// Question: Insert an Element at the Bottom of a Stack
// Description: You are given a stack st of n integers and an element x. You have to insert x at the bottom of the given stack. 

//              Note: Everywhere in this problem, the bottommost element of the stack is shown first while priniting the stack.
// Approach: 1. Code is Self-Explanatory.

class Solution{
public:
    stack<int> insertAtBottom(stack<int> St,int X){
        solve(St, X);
        
        return St;
    }
    
    void solve(stack<int>& St, int X){
        int temp = St.top();
        St.pop();
        
        if(St.empty()) St.push(X);
        else solve(St, X);
        St.push(temp);
    }
};