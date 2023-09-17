// DATE: 17-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1
// Question: Print first n fibonacci numbers
// Description: For a given integer n, print first n fibonacci numbers, where first two integers are 1 and 1.
// Approach: 1. Self explanatory.

class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        vector<long long> v;
        long long a = 1, b = 1, c = 0;
        
        if(n == 1){
            v.push_back(1);
            return v;
        }
        else if(n == 2){
            v.push_back(1);
            v.push_back(1);
            return v;
        }
        
        v.push_back(1);
        v.push_back(1);
        
        for(int i = 0; i < n-2; i++){
            c = a + b;
            v.push_back(c);
            a = b;
            b = c;
        }
        
        return v;
    }
};