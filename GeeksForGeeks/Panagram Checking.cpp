// DATE: 01-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1
// Question: Panagram Checking
// Description: Given a string s check if it is "Panagram" or not.

//              A "Panagram" is a sentence containing every letter in the English Alphabet.
// Approach: 1. For any alphabet occurence make ith bit set in ans. Then check if ans == 67108863.

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 65 && s[i] <= 90) ans = ans | (1 << s[i] - 'A');
            else if(s[i] >= 97 && s[i] <= 122) ans = ans | (1 << s[i] - 'a');
        }
        
        return ans == 67108863;
    }

};