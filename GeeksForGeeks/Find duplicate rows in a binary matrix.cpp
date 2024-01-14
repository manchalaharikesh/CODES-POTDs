// DATE: 14-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/
// Question: Find duplicate rows in a binary matrix
// Description: Given a boolean matrix of size RxC where each cell contains either 0 or 1, find the row numbers (0-based) of row which already exists or are repeated.
// Approach: 1. Solution is based on tries. We store each row in trie and if at any time we need to create a new node in existing trie the row is unique and not otherwise.

class TrieNode{
    public:
    TrieNode* arr[2] = {NULL, NULL};
};

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        vector<int> ans;
        TrieNode *root = new TrieNode(), *temp = NULL;
        bool flag = false;
        
        for(int i = 0; i < M; i++){
            flag = false;
            temp = root;
            for(int j = 0; j < N; j++){
                if(temp->arr[matrix[i][j]] != NULL) temp = temp->arr[matrix[i][j]];
                else{
                    temp->arr[matrix[i][j]] = new TrieNode();
                    temp = temp->arr[matrix[i][j]];
                    flag = true;
                }
            }
            
            if(!flag) ans.push_back(i);
        }
        
        return ans;
    } 
};