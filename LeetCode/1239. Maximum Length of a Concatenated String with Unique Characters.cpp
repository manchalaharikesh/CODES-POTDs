// DATE: 23-JAN-2024
// Question URL: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/

// Question: 1239. Maximum Length of a Concatenated String with Unique Characters
// Description: You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

//              Return the maximum possible length of s.

//              A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// Approach: 1. Store each string char as a set bit of a number. Then by backtracking approach go through all the possibilities and find the max length of string possible.

class Solution {
public:
    void bt(int idx, int n, vector<string>& arr, vector<int>& mat, vector<bool>& hasDup, int pat, int temp, int& ans){
        if(idx == n){
            ans = ans > temp ? ans : temp;
            return ;
        }

        for(int i = idx; i < n; i++){
            if(!hasDup[i]){
                if(!(pat & mat[i])){
                    pat = pat | mat[i];
                    temp += arr[i].length();
                    bt(i + 1, n, arr, mat, hasDup, pat, temp, ans);
                    temp -= arr[i].length();
                    pat = pat & (~mat[i]);
                }
            }
            bt(i + 1, n, arr, mat, hasDup, pat, temp, ans);
        }
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> mat(n, 0);
        vector<bool> hasDup(n, false);
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < arr[i].length(); j++){
                if(mat[i] & (1 << (arr[i][j] - 'a'))){
                    hasDup[i] = true;
                    break;
                }
                else{
                    mat[i] = mat[i] | (1 << (arr[i][j] - 'a'));
                }
            }
        }

        bt(0, n, arr, mat, hasDup, 0, 0, ans);

        return ans;
    }
};