// DATE: 13-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1
// Question: Print matrix in diagonal pattern
// Description: Given a square matrix mat[][] of n*n size, the task is to determine the diagonal pattern which is a linear arrangement of the elements of the matrix as depicted in the following example:
// 1 2 3
// 4 5 6
// 7 8 9
// ans: 1 4 2 3 5 7 8 6 9
// Approach: 1. Transpose matrix and store it. Now for ans vector, if it is a even diagonal traverse bottom to up in old mat else traverse bottom to up in new matrix.

lass Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        vector<vector<int>> new_mat(mat[0].size(), vector<int>(mat.size()));
        vector<int> ans;
        int diagonal = 2*mat.size()-1, mid = diagonal/2 + diagonal%2, row = 0, col = 1;
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                new_mat[j][i] = mat[i][j];
            }
        }
        
        for(int k = 0; k < diagonal; k++){
            if(k < mid){
                for(int i = row; i >= 0; i--){
                    ans.push_back(k % 2 == 0 ? mat[i][k-i] : new_mat[i][k-i]);
                }
                row++;
            }
            else{
                int i = row-1;
                for(int j = col; j < mat.size(); j++){
                    ans.push_back(k % 2 == 0 ? mat[i][j] : new_mat[i][j]);
                    i--;
                }
                col++;
            }
        }
        
        return ans;
    }
};