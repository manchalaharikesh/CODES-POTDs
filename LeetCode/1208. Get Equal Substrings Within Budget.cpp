// DATE: 29-MAY-2024
// Question URL: https://leetcode.com/problems/get-equal-substrings-within-budget/description/

// Question: 1208. Get Equal Substrings Within Budget
// Description: You are given two strings s and t of the same length and an integer maxCost.

//              You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

//              Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.
// Approach: 1. The following solution uses a sliding window approach.
//              It tries to inc p2 as long as the substring from p1 to p2 is convertible under given maxCost i.e., maxCost - abs(s[p2]-t[p2]) >= 0.
//              If p2 can't be further incremented with available cost we update ans with current substring length ans = max(ans, p2-p1).
//              Then we also inc p1 at same time we also inc maxCost by maxCost = maxCost + abs(s[p1] - t[p1]).
//              This way the final ans will be the max substring length possible.

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int p1 = 0, p2 = 0, ans = 0;

        while(p2 < s.length()){
            if(abs(s[p2]-t[p2]) <= maxCost){
                maxCost -= abs(s[p2]-t[p2]);
                p2++;
            }
            else{
                if(p1 != p2){
                    maxCost += abs(s[p1] - t[p1]);
                }
                p1++;
            }
            
            ans = max(ans, p2 - p1);
            
            if(p1 > p2) p2 = p1;
        }

        return ans;
    }
};