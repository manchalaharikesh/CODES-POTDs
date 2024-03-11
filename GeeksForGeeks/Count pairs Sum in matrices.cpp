// DATE: 11-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1
// Question: Count pairs Sum in matrices
// Description: Given two sorted matrices mat1 and mat2 of size n x n of elements. Each matrix contains numbers arranged in strictly ascending order, with each row sorted from left to right, and the last element of a row being smaller than the first element of the next row. You're given a target value, x, your task is to find and count all pairs {a, b} such that a is from mat1 and b is from mat2 where sum of a and b is equal to x.
// Approach: 1. Store the freq of elements of mat2 in map. Now for each element in mat1 find x-mat1[i][j] if it exists in map, add it to ans.

class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    map<int, int> m;
	    int ans = 0;
	    
	    for(int i = 0; i < mat2.size(); i++){
	        for(int j = 0; j < mat2[0].size(); j++){
	            m[mat2[i][j]]++;
	        }
	    }
	    
	    for(int i = 0; i < mat1.size(); i++){
	        for(int j = 0; j < mat1[0].size(); j++){
	            if(m.find(x-mat1[i][j]) != m.end()) ans += m[x-mat1[i][j]];
	        }
	    }
	    
	    return ans;
	}
};