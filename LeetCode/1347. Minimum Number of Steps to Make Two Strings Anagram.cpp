// DATE: 13-JAN-2024
// Question URL: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13

// Question: 1347. Minimum Number of Steps to Make Two Strings Anagram
// Description: You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

//              Return the minimum number of steps to make t an anagram of s.

//              An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.
// Approach: 1. As both the string s and t are of equal length, just count the number of characters in s without an equivalent pair in t or vice versa.

class Solution {
public:
    int minSteps(string s, string t) {
        int c[26] = {0};
        int n = s.length(), ans = 0;

        for(int i = 0; i < n; i++){
            c[s[i] % 97]++;
            c[t[i] % 97]--;
        }

        for(int i = 0; i < 26; i++){
            ans = ans + abs(c[i]);
        }

        return ans / 2;
    }
};