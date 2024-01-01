// DATE: 01-JAN-2024
// Question URL: https://leetcode.com/problems/assign-cookies/description/

// Question: 455. Assign Cookies
// Description: Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

//              Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
// Approach: 1. Sort both the greed and size lists and iterate throught the greed of each child and choose suitable size of cookie, and note that if s[j] >= g[i] no other cookie size (< j) is not suitable for child greed (> i) as lists are sorted.

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for(int i = 0; i < g.size(); i++){
            while(j < s.size()){
                if(s[j] >= g[i]){
                    ans++;
                    j++;
                    break;
                }
                j++;
            }
        }

        return ans;
    }
};