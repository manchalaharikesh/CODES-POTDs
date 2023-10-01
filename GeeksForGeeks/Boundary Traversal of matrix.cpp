// DATE: 01-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-matrix-1587115620/1
// Question: Boundary Traversal of matrix
// Description: For a given matrix, traverse across the boundary of it.
// Approach: 1. Code - Self Explanatory.

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        vector<int> ans;
        
        for(int j = 0; j < m; j++){
            ans.push_back(matrix[0][j]);    
        }
        
        if(n == 1) return ans;
        
        for(int i = 1; i < n; i++){
            ans.push_back(matrix[i][m-1]);    
        }
        
        for(int j = m-2; j >= 0; j--){
            ans.push_back(matrix[n-1][j]);    
        }
        
        if(m == 1) return ans;
        
        for(int i = n-2; i > 0; i--){
            ans.push_back(matrix[i][0]);    
        }
        
        return ans;
    }
};