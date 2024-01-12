// DATE: 12-JAN-2024
// Question URL: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/

// Question: 1704. Determine if String Halves Are Alike
// Description: You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

//              Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

//              Return true if a and b are alike. Otherwise, return false.
// Approach: 1. Have a counter for vowel count on either halves inc counter for 1st half and dec for 2nd half and return counter == 0.

class Solution {
public:
    bool halvesAreAlike(string s) {
        int c = 0, mid = s.length()/2;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                if(i < mid) c++;
                else c--;
            }
        }

        return c == 0;
    }
};