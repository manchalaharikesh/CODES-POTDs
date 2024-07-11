// DATE: 11-JUL-2024
// Question URL: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/

// Question: 1190. Reverse Substrings Between Each Pair of Parentheses
// Description: You are given a string s that consists of lower case English letters and brackets.

//              Reverse the strings in each pair of matching parentheses, starting from the innermost one.

//              Your result should not contain any brackets.
// Approach: 1. Please Dry Run the code as it is best to understand than a descriptive explanation.

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string temp;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') st.push("(");
            else if((s[i] >= 'a' && s[i] <= 'z') || s[i] ==')'){
                temp = "";
                while(i < s.length() && s[i] != '(' && s[i] != ')'){
                    temp += s[i++];
                }

                if(i == s.length()){
                    if(!st.empty()){ 
                        temp = st.top() + temp;
                        st.pop();
                    }
                    st.push(temp);
                    break;
                }

                if(s[i] == '('){ 
                    if(!st.empty() && st.top() != "("){ 
                        temp = st.top() + temp;
                        st.pop();
                    }
                    st.push(temp);
                    st.push("(");
                }
                else{
                    if(!st.empty() && st.top() != "("){
                        temp = st.top() + temp;
                        st.pop();
                    }
                    if(!st.empty() && st.top() == "(") st.pop();
                    reverse(temp.begin(), temp.end());
                    // cout << temp << "\n";
                    if(!st.empty() && st.top() != "("){
                        temp = st.top() + temp;
                        st.pop();
                    }
                    st.push(temp);
                }
            }
        }

        return st.top();
    }
};