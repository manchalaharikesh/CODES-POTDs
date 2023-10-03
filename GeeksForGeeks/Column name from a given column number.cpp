// DATE: 03-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1
// Question: Column name from a given column number
// Description: For a given integer N, print the correct column name for it in excel sheet.
// Approach: 1. Look the integer N of decimal system (base 10) in system with (base 26).

class Solution{
    public:
    string colName (long long int n)
    {
        string ans = "";

        while(n != 0){
            int rem = n % 26;
            ans = char(64 + (rem == 0 ? 26 : rem)) + ans;
            if(rem == 0) n--;
            n /= 26;
        }

        return ans;
    }
};