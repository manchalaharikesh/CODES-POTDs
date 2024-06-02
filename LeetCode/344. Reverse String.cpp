// DATE: 02-MAY-2024
// Question URL: https://leetcode.com/problems/reverse-string/description/

// Question: 344. Reverse String
// Description: Write a function that reverses a string. The input string is given as an array of characters s.

//              You must do this by modifying the input array in-place with O(1) extra memory.
// Approach: 1. Two pointer concept to reverse a string with swapping of varabiles without a temp variable.

class Solution {
public:
    void reverseString(vector<char>& s) {
        int p1 = 0, p2 = s.size()-1;

        while(p1 < p2){
            s[p1] = s[p1] + s[p2];
            s[p2] = s[p1] - s[p2];
            s[p1] = s[p1] - s[p2];

            p1++;
            p2--;
        }
    }
};