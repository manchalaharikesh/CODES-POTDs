// DATE: 02-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/implement-atoi/1
// Question: Implement Atoi
// Description: Given a string, s, the objective is to convert it into integer format without utilizing any built-in functions. If the conversion is not feasible, the function should return -1.

//              Note: Conversion is feasible only if all characters in the string are numeric or if its first character is '-' and rest are numeric.
// Approach: 1. Code - Self Explanatory.

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int i = s[0] == '-' ? 1 : 0, ans = 0;
        bool isNeg = s[0] == '-';
        
        for(; i < s.length(); i++){
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9) ans = ans * 10 + (s[i] - '0');
            else return -1;
        }
        
        return isNeg ? -ans : ans;
    }
};