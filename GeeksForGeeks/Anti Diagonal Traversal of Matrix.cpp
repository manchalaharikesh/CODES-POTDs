// DATE: 27-DEC-2023
// Question URL: https://www.geeksforgeeks.org/problems/print-diagonally1623/1
// Question: Anti Diagonal Traversal of Matrix
// Description: Give a N*N square matrix, return an array of its anti-diagonals in top-leftmost to bottom-rightmost order. In an element of a anti-diagonal (i, j), surrounding elements will be (i+1, j-1) and (i-1, j+1). Look at the examples for more clarity.
// Approach: 1. Store elements into the map based on their index sum (i+j) as key. Then put elements into ans vector in ascending order of their key values.

class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        map<int, vector<int>> hm;
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(hm.find(i+j) == hm.end()){
                    vector<int> temp;
                    temp.push_back(matrix[i][j]);
                    hm.insert(pair<int, vector<int>>(i+j, temp));
                }
                else{
                    hm[i+j].push_back(matrix[i][j]);
                }
            }
        }
        
        for(int i = 0; i <= 2*(m-1); i++){
            for(int j = 0; j < hm[i].size(); j++){
                ans.push_back(hm[i][j]);
            }
        }
        
        return ans;
    }
};