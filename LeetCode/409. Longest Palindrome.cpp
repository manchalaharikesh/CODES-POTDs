// DATE: 04-JUN-2024
// Question URL: https://leetcode.com/problems/longest-palindrome/description/

// Question: 409. Longest Palindrome
// Description: Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
//              palindrome that can be built with those letters.
//              Letters are case sensitive, for example, "Aa" is not considered a palindrome.
// Approach: 1. To construct a palindrome out of characters we need all to be even in count but can accept one character to be odd (which occupies the center) e.g.: abcccba.
//              Thus when we have even char freq we take it all. But when we have an odd freq we only take even (freq-1) from it.
//              But at the end if we had any odd freq occured we can add one bonus char to total count as we can place this odd freq at the center.
//              Code is Self-Explanatory.

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        bool odd = false;
        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            m[s[i]]++;
        }

        for(auto it: m){
            if(it.second % 2 == 0) ans = ans + it.second;
            else{
                odd = true;
                ans = ans + it.second - 1;
            }
        }

        return odd ? ans + 1 : ans;
    }
};