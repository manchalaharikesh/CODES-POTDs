// DATE: 04-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1

// Question: Roman Number to Integer
// Description: Given a string representing a roman number convert it into an integer of decimal system. 
// Approach: 1. Brute Force.

class Solution {
  public:
    int romanToDecimal(string &str) {
        char a[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int b[7] = {1, 5, 10, 50, 100, 500, 1000};
        unordered_map<char, int> hm;
        
        int sum = 0, temp;
        char prev = NULL;
        stack<char> ch;
        stack<int> st;
        
        for(int i = 0; i < 7; i++){
            hm.insert({a[i], b[i]});
        }
        
        for(int i = 0; i < str.length(); i++){
            if(!st.empty() && ch.top() == str[i]){
                temp = st.top();
                st.pop();
                temp += hm[str[i]];
                st.push(temp);
            }
            else{
                st.push(hm[str[i]]);
                ch.push(str[i]);
            }
        }
        
        while(!st.empty()){
            if(prev == NULL || hm[prev] < hm[ch.top()]){
                sum += st.top();
                st.pop();
                prev = ch.top();
                ch.pop();
            }
            else{
                sum -= st.top();
                st.pop();
                prev = ch.top();
                ch.pop();
            }
        }
        
        return sum;
    }
};