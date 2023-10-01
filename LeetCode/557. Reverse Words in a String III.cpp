// DATE: 01-OCT-2023
// Question URL: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

// Question: 557. Reverse Words in a String III
// Description: Given a string make the reverse of the each of the word in the string while preserving order of the words.
// Approach: 1. Code Self-Explanatory.

class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans = "";
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                reverse(temp.begin(), temp .end());
                ans = ans + temp + " ";
                temp = "";
            }
            else{
                temp += s[i];
            }
        }

        reverse(temp.begin(), temp .end());
        ans += temp;
    
        return ans;
    }
};