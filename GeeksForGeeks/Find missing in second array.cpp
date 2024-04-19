// DATE: 19-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/in-first-but-second5423/1
// Question: Find missing in second array
// Description: Given two integer arrays a of size n and b of size m, the task is to find the numbers which are present in the first array a, but not present in the second array b.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution{
	
	
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    vector<int> ans;
	    set<int> s;
	    for(int i = 0; i < m; i++){
	        s.insert(b[i]);
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(s.find(a[i]) == s.end()){
	            ans.push_back(a[i]);
	        }
	    }
	    
	    return ans;
	} 
};