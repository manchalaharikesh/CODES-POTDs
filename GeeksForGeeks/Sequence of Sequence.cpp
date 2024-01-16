// DATE: 16-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1
// Question: Sequence of Sequence
// Description: Given two integers m and n, try making a special sequence of numbers seq of length n such that

//              seqi+1 >= 2*seqi 
//              seqi > 0
//              seqi <= m
//              Your task is to determine total number of such special sequences possible.
// Approach: 1. Brute Force to iterate with values in possible range at every index and increment counter for possible sequences.

class Solution{
public:
    void solve(int m, int n, int i, int prev, int& ans){
        int _min = 2*prev, _max = m / (1 << (n - (i + 1)));
        
        if(i == n - 1){
            ans = ans + (m - _min + 1);
            return ;
        }
        
        for(int val = _min; val <= _max; val++){
            solve(m, n, i+1, val, ans);
        }
    }
    
    int numberSequence(int m, int n){
        if(n == 1) return m;
        else if(n >= 8) return 0;
        
        int ans = 0, _min = 1, _max = m / (1 << (n - 1));
        for(int val = _min; val <= _max; val++)
            solve(m, n, 1, val, ans);
        
        return ans;
    }
};