// DATE: 11-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/juggler-sequence3930/1
// Question: Juggler Sequence
// Description: Juggler Sequence is a series of integers in which the first term starts with a positive integer number a and the remaining terms are generated from the immediate previous term using the below recurrence relation:
//              a[k+1] = a[k] is even ? sqrt(a[k]) : sqrt(a[k])*a[k]
//              Given a number n, find the Juggler Sequence for this number as the first term of the sequence until it becomes 1.
// Approach: 1. Brute Force / Code Self Explanatory.

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        vector<int> ans;
        int s = 0;
        
        ans.push_back(n);
        
        if(n == 1) return ans;
        
        while(true){
            if(ans[s] % 2 == 0){
                ans.push_back(int(pow(ans[s], 0.5)));
            }
            else{
                ans.push_back(int(pow(ans[s], 0.5)*ans[s]));
            }
            
            s++;
            if(ans[s] == 1) break;
        }
        
        return ans;
    }
};