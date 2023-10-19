// DATE: 19-OCT-2023
// Question URL: https://leetcode.com/problems/backspace-string-compare/

// Question: 844. Backspace String Compare
// Description: Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

//              Note that after backspacing an empty text, the text will continue empty.
// Approach: 1. Use stack to push chars and pop upon back spaces, then compare the final result by taking the strings from stack.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "", s2 = "";
        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#' && !st.empty()){
                st.pop();
            }
            else if(s[i] != '#') st.push(s[i]);
        }

        while(!st.empty()){
            s1 = st.top() + s1;
            st.pop();
        }

        for(int i = 0; i < t.length(); i++){
            if(t[i] == '#' && !st.empty()){
                st.pop();
            }
            else if(t[i] != '#') st.push(t[i]);
        }

        while(!st.empty()){
            s2 = st.top() + s2;
            st.pop();
        }

        return s1 == s2;
    }
};