// DATE: 28-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1
// Question: Check if a number is divisible by 8
// Description: Given a string representation of a decimal number s, check whether it is divisible by 8.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution{
    public:
    int DivisibleByEight(string s){
        int c = 0;
        
        if(s.length() == 1) return s[0] == '8';
        else if(s[s.length()-1] % 2 != 0) return -1;
        
        for(int i = 0; i < s.length(); i++){
            if(c*10 + (s[i] - '0') < 8){
                c = c*10 + (s[i] - '0');
            }
            else{
                c = (c*10 + (s[i] - '0')) % 8;
            }
        }
        
        return c == 0 ? 1 : -1;
    }
};