// DATE: 13-FEB-2024
// Question URL: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/

// Question: 2108. Find First Palindromic String in the Array
// Description: Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

//              A string is palindromic if it reads the same forward and backward.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
public:
    bool isPal(string& s){
        int p1 = 0, p2 = s.length()-1;

        while(p1 < p2){
            if(s[p1] != s[p2]) return false;
            p1++;
            p2--;
        }

        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            if(isPal(words[i])) return words[i];
        }

        return "";
    }
};