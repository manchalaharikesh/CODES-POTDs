// DATE: 31-DEC-2023
// Question URL: https://leetcode.com/problems/largest-substring-between-two-equal-characters/

// Question: 1624. Largest Substring Between Two Equal Characters
// Description: Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

//              A substring is a contiguous sequence of characters within a string.
// Approach: 1. Brute Force.

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        int ans = -1, temp;

        for(int i = 0; i < n; i++){
            for(int j = n-1; j > i; j--){
                if(s[i] == s[j]){
                    temp = j-i-1;
                    ans = ans < temp ? temp : ans;
                }
            }
        }

        return ans;
    }
};