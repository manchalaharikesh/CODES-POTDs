// DATE: 01-JUN-2024
// Question URL: https://leetcode.com/problems/score-of-a-string/description/

// Question: 3110. Score of a String
// Description: You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

//              Return the score of s.

// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;

        for(int i = 0; i < s.length()-1; i++){
            ans = ans + abs(s[i]-s[i+1]);
        }

        return ans;
    }
};