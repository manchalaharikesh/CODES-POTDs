// DATE: 23-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/print-bracket-number4058/1
// Question: Print Bracket Number
// Description: Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string.
// Approach: 1. Brute Force / Code is Self-Explanatory.

class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        vector<int> ans;
        stack<int> st;
        int c = 0;
        
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '('){ 
                c++;
                st.push(c);
                ans.push_back(st.top());
            }
            else if(str[i] == ')'){
                ans.push_back(st.top());
                st.pop();
            }
        }
        
        return ans;
    }
};