// DATE: 05-FEB-2024
// Question URL: https://leetcode.com/problems/first-unique-character-in-a-string/description/

// Question: 387. First Unique Character in a String
// Description: Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
// Approach: 1. Code is Self-Explanatory.

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};

        for(int i = 0; i < s.length(); i++){
            arr[s[i] - 'a']++;
        }

        for(int i = 0; i < s.length(); i++){
            if(arr[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};