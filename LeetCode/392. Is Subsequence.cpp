// DATE: 22-SEP-2023
// Question URL: https://leetcode.com/problems/is-subsequence/

// Question: 392. Is Subsequence
// Description: Given two strings s and t check whether s is a subsequence of t or not.
// Approach: 1. Brute Force iterative approach TC: O(N).

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        int s1 = s.length(), s2 = t.length();

        if(s1 > s2) return false;

        for(int i = 0; i < s2; i++){
            if(s[idx] == t[i]) idx++;
            if(idx == s1) return true;
        }

        if(s == "") return true;

        return false;
    }
};