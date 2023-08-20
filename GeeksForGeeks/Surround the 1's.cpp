// DATE: 21-AUG-2023
// Question URL: https://practice.geeksforgeeks.org/problems/surround-the-1s2505/1

// Question: Surround the 1's.
// Description: For a given matrix of size 'M*N' print the count of 1's which are surrounded by even number of 0's in 8 adjacency.
// Approach: 1. Iterate over the matrix and check for number of 0's in the 8-adjacency for every occurence of 1.
//           2. If the counter is not zero and even number then increment the ans.

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int c = 0;
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int even = 0;
                if(matrix[i][j] == 0) continue;
                // left
                if(i-1 >= 0 && matrix[i-1][j] == 0) even++;
                // top
                if(j-1 >= 0 && matrix[i][j-1] == 0) even++;
                // right
                if(i+1 < m && matrix[i+1][j] == 0) even++;
                // down
                if(j+1 < n && matrix[i][j+1] == 0) even++;
                // top left
                if(i-1 >= 0 && j-1 >= 0 && matrix[i-1][j-1] == 0) even++;
                // top right
                if(i-1 >= 0 && j+1 < n && matrix[i-1][j+1] == 0) even++;
                // bottom left
                if(i+1 < m && j-1 >= 0 && matrix[i+1][j-1] == 0) even++;
                // bottom right
                if(i+1 < m && j+1 < n && matrix[i+1][j+1] == 0) even++;
                
                if(even != 0 && even % 2 == 0) c++;
            }
        }
        
        return c;
    }
};