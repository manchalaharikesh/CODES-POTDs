// DATE: 13-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/largest-number-possible5028/1
// Question: Largest Number Possible
// Description: Given number N (number of digits) and S (sum of digits of number to be formed), find the maximum number possible with N digits whose sum of digits is S.
// Approach: 1. Code is self explanatory.

class Solution{
public:
    string findLargest(int N, int S){
        string str = "";
        
        if((N > 1 && S == 0) || S > 9*N) return "-1";
        
        while(S > 0 && N > 0){
            if(S >= 10){
                str = str + '9';
                S -= 9;
            }
            else{
                str = str + char(48 + S);
                S = 0;
            }
            N--;
        }
        
        while(N > 0){
            str = str + '0';
            N--;
        }
        
        return str;
    }
};