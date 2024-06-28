// DATE: 28-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1

// Question: The Palindrome Pattern
// Description: Given a two-dimensional integer array arr of dimensions n x n, consisting solely of zeros and ones, identify the row or column (using 0-based indexing) where all elements form a palindrome. If multiple palindromes are identified, prioritize the palindromes found in rows over those in columns. Within rows or columns, the palindrome with the smaller index takes precedence. The result should be represented by the index followed by either 'R' or 'C', indicating whether the palindrome was located in a row or column. The output should be space-separated. If no palindrome is found, return the string -1.
// Approach: 1. Check for palindrome in each row initially then if not found check in each column if not found return -1 otherwise whenever it is found consider it as rows are preferenced over cols and smaller index is preferenced all the time.
//              Refer to code as it is Self-Explanatory.

class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        bool flag;
        int p1, p2;
        string s = "";
        
        for(int i = 0; i < arr.size(); i++){
            flag = true;
            p1 = 0;
            p2 = arr[0].size()-1;
            
            while(p1 < p2){
                if(arr[i][p1] != arr[i][p2]){
                    flag = false;
                    break;
                }
                p1++;
                p2--;
            }
            
            if(flag){
                s = to_string(i) + " R";
                return s;
            }
        }
        
        for(int j = 0; j < arr[0].size(); j++){
            flag = true;
            p1 = 0;
            p2 = arr.size()-1;
            
            while(p1 < p2){
                if(arr[p1][j] != arr[p2][j]){
                    flag = false;
                    break;
                }
                p1++;
                p2--;
            }
            
            if(flag){
                s = to_string(j) + " C";
                return s;
            }
        }
        
        return "-1";
    }
};