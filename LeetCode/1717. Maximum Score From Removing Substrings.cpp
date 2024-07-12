// DATE: 12-JUL-2024
// Question URL: https://leetcode.com/problems/maximum-score-from-removing-substrings/description/

// Question: 1717. Maximum Score From Removing Substrings
// Description: You are given a string s and two integers x and y. You can perform two types of operations any number of times.

//              Remove substring "ab" and gain x points.
//              For example, when removing "ab" from "cabxbae" it becomes "cxbae".
//              Remove substring "ba" and gain y points.
//              For example, when removing "ba" from "cabxbae" it becomes "cabxe".
//              Return the maximum points you can gain after applying the above operations on s.
// Approach: 1. In the given second example of this question "aabbaaxybbaabb", x = 5, y = 4 we must give more preference to "ab" as x > y.
//              But while removing the substrings in "..bbaabb" we see only 2 "ba" substrings in the start and remove them, but we also had the choice to remove "aabb" as 2 "ab" substrings which gives more points.
//              So to tackle this issue at first we need to remove only those substrings from the whole string which give us more points ("ab" if x > y else "ba") and then remove the other substring from same string.
//              We use stack based greedy approach in this solution where, lets say we have to remove "ab" substrings, we push other characters otherthan 'a', 'b' directly into the stack, and for s[i] to be 'b' we compare with stack top to be 'a' to pop remove them.
//              The same approach is also used while performing substring removal for "ba".
//              Please refer to code for better understanding.

class Solution {
public:
    int solve(string& s, char f, char l, int val){
        stack<int> st;
        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && s[st.top()] == f && s[i] == l){
                s[st.top()] = '*';
                s[i] = '*';
                st.pop();
                ans = ans + val;
            }
            else if(s[i] != '*') st.push(i);
        }

        return ans;
    }
    int maximumGain(string s, int x, int y) {
        int ans = 0;

        if(x > y){
            ans = solve(s, 'a', 'b', x);
            ans = ans + solve(s, 'b', 'a', y);
        }
        else{
            ans = solve(s, 'b', 'a', y);
            ans = ans + solve(s, 'a', 'b', x);
        }

        return ans;
    }
};