// DATE: 11-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/recamans-sequence4856/1
// Question: Recamans sequence
// Description: Given an integer n, return the first n elements of Recaman’s sequence.
//              It is a function with domain and co-domain as whole numbers. It is recursively defined as below:
//              Specifically, let a(n) denote the (n+1)th term. (0 being the 1st term).
//              The rule says:
//              a(0) = 0
//              a(n) = a(n-1) - n, if a(n-1) - n > 0 and is not included in the sequence previously
//                   =  a(n-1) + n otherwise.
// Approach: 1. Code is Self-Explanatory.

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> ans(n, 0);
        map<int, int> m;
        int val;
        
        m[0] = 1;
        
        for(int i = 1; i < n; i++){
            val = ans[i-1] - i;
            if(val < 0 || m.find(val) != m.end()) ans[i] = ans[i-1]+i;
            else ans[i] = val;
            
            m[ans[i]] = 1;
        }
        
        return ans;
    }
};