// DATE: 22-AUG-2023
// Question URL: https://leetcode.com/problems/excel-sheet-column-title/

// Question: 168. Excel Sheet Column Title
// Description: For a given number N generate the possible Excel sheet column name for it.
// Approach: 1. Consider a number system of base 26 and convert given number N into base 26 number system.

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while(columnNumber != 0){
            int rem = columnNumber % 26;
            ans = char(64 + (rem == 0 ? 26 : rem)) + ans;
            if(rem == 0) columnNumber--;
            columnNumber /= 26;
        }

        return ans;
    }
};