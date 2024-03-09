// DATE: 09-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1
// Question: Find the N-th character
// Description: Given a binary string s. Perform r iterations on string s, where in each iteration 0 becomes 01 and 1 becomes 10. Find the nth character (considering 0 based indexing) of the string after performing these r iterations (see examples for better understanding).
// Approach: 1. First find the index whose r iterations would contain the final index n. Now for that index iteratively find which path would lead to required index n. For more details look into code.

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        int max_gen = 1 << r;
        int idx = n / max_gen;
        int completed = idx*max_gen;
        char ch = s[idx];
        
        while(r--){
            if(n < completed + max_gen / 2){
                max_gen /= 2;
            }
            else{
                ch = ch == '0' ? '1' : '0';
                completed = completed + max_gen / 2;
                max_gen /= 2;
            }
            
        }
        
        return ch;
    }
};