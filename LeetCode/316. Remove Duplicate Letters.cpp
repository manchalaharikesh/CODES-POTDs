// DATE: 26-SEP-2023
// Question URL: https://leetcode.com/problems/remove-duplicate-letters/

// Question: 316. Remove Duplicate Letters
// Description: Given a string s, convert it to a string of unique characters by preserving the order and form the lexiographically smallest possible string.
// Approach: 1. Self-Explanatory.

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        int n = s.length();

        stack<char> st;
        bool visited[26] = {false};

        string ans = "";

        for(int i = 0; i < n; i++){
            count[s[i] - 97]++;
        }

        for(int i = 0; i < n; i++){
            char ch = s[i];
            count[ch - 97]--;

            if(!visited[ch - 97]){
                while(!st.empty() && st.top() > ch){
                    if(count[st.top() - 97] > 0){
                        visited[st.top() - 97] = false;
                        st.pop();
                    }
                    else{
                        break;
                    }
                }

                st.push(ch);
                visited[ch - 97] = true;
            }
        }

        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};