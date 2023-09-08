// DATE: 08-SEP-2023
// Question URL: https://leetcode.com/problems/pascals-triangle/

// Question: 118. Pascal's Triangle
// Description: Given an integer numRows, return the first numRows of Pascal's triangle.
// Approach: 1. Apply DP by generating ith row from (i-1)th row.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        int level=2;
        if(numRows==1)  return ans;
        if(numRows > 1){
            level++;
            ans.push_back({1,1});
        }
        if(numRows == 2)    return ans;

        for(int i=level;i<=numRows;i++){
            vector<int> l;
            l.push_back(1);
            for(int j=1;j<i-1;j++){
                l.push_back(ans[i-2][j-1]+ans[i-2][j]);
            }
            l.push_back(1);
            ans.push_back(l);
        }

        return ans;
    }
};