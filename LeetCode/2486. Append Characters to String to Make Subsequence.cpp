// DATE: 03-JUN-2024
// Question URL: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/

// Question: 2486. Append Characters to String to Make Subsequence
// Description: You are given two strings s and t consisting of only lowercase English letters.

//              Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

//              A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

// Approach: 1. The idea is to find characters of t in s with the order as in t
//              Have two pointers to iterate s and t.
//              When we have a character match between s[i] and t[j] we increment both pointers.
//              If there is no match we only increment pointer i.
//              We repeat this until any one of the string is reached its end.
//              The final answer would be the number of characters that left in t that didn't find a match i.e., |t|-j.

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(), m = t.size(), j = 0;

        for(int i = 0; i < n && j < m; i++){
            if(s[i] == t[j]) j++;
        }

        return m - j;
    }
};