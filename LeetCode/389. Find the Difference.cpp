// DATE: 25-SEP-2023
// Question URL: https://leetcode.com/problems/find-the-difference/

// Question: 389. Find the Difference
// Description: Given two strings s and t where t is made of all the characters from s in some random order and then added a single other character. Find the extra character.
// Approach: 1. Increment the count of characters in s in a count array and decrement the count for characters in t.
//              Then for the character whose count is not 0 is the extra character.

class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26] = {0};
        char ch;

        for(int i = 0; i < t.length(); i++){
            arr[t[i]-97]++;
        }

        for(int i = 0; i < s.length(); i++){
            arr[s[i]-97]--;
        }

        for(int i = 0; i < 26; i++){
            if(arr[i]) ch = 97 + i;
        }

        return ch;
    }
};