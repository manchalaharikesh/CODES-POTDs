// DATE: 22-FEB-2025
// Question URL: https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1
// Question: Longest valid Parentheses
// Description: Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

//              A parenthesis string is valid if:

//              For every opening parenthesis, there is a closing parenthesis.
//              The closing parenthesis must be after its opening parenthesis.
// Approach: 1. Store the idx of '(' in stack, for every successful match with ')' 
//              mark both idxs of '(' (stored in stack) and ')' (curr i in iterator) to '*'
//              Now iterate the string to see longest substring of '*'.

class Solution {
  public:
    int maxLength(string& s) {
        stack<int> st;
        int ans = 0, l = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')' && !st.empty() && s[st.top()] == '('){ 
                s[st.top()] = '*';
                st.pop();
                s[i] = '*';
            }
            else if(s[i] == '(') st.push(i);
        }
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                l++;
            }
            else{
                ans = max(ans, l);
                l = 0;
            }
        }
        ans = max(ans, l);
        
        return ans;
    }
};