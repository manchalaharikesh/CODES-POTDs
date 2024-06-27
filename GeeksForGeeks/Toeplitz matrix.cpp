// DATE: 27-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/toeplitz-matrix/1

// Question: Toeplitz matrix
// Description: A Toeplitz (or diagonal-constant) matrix is a matrix in which each descending diagonal from left to right is constant, i.e., all elements in a diagonal are the same. Given a rectangular matrix mat, your task is to complete the function isToeplitz which returns 1 if the matrix is Toeplitz otherwise, it returns 0.
// Approach: 1. We just need to traver the matrix diagonally, Dry Run the code for better understanding.

bool isToepliz(vector<vector<int>>& mat) {
    int k = 0, ele;
    
    for(int i = 0; i < mat.size(); i++){
        ele = mat[i][0];
        k = i+1;
        for(int j = 1; j < mat[0].size() && k < mat.size(); j++){
            if(mat[k][j] != ele) return 0;
            k++;
        }
    }
    
    for(int j = 1; j < mat[0].size(); j++){
        ele = mat[0][j];
        k = j+1;
        for(int i = 1; i < mat.size() && k < mat[0].size(); i++){
            if(mat[i][k] != ele) return 0;
            k++;
        }
    }
    
    return 1;
}