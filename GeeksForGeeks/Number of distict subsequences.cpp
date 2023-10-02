// DATE: 02-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1

// Question: Number of distinct subsequences
// Description: For a given string s find the number of unique subsequences, as the result might be large return output with mod 10^9+7.
// Approach: 1. self explanatory TC: O(|str|) SC: O(|str|).

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int n = s.length();
	    int mod = 1000000007;
	    long long k = 0;
	    vector<int> hm(26, -1);
	    vector<long long> inclusive(n, 0);
	    vector<long long> exclusive(n, 0);
	    
	    if(n == 0) return 1;
	    
	    inclusive[n-1] = 1;
	    hm[s[n-1] - 97] = n-1;
	    
	    for(int i = n-2; i >= 0; i--){
	        inclusive[i+1] = inclusive[i+1] % mod;
	        exclusive[i+1] = exclusive[i+1] % mod;
	        
	        if(hm[s[i] - 97] == -1){
	            hm[s[i] - 97] = i;
	            inclusive[i] = (inclusive[i+1] + exclusive[i+1] + 1) % mod;
	        }
	        else{
	            exclusive[hm[s[i] - 97]] = exclusive[hm[s[i] - 97]] % mod;
	            k = (inclusive[i+1] + exclusive[i+1]) % mod;
	            
	            if((k - exclusive[hm[s[i] - 97]]) % mod < 0) k = (k - exclusive[hm[s[i] - 97]]) % mod + mod;
	            else k = (k - exclusive[hm[s[i] - 97]] + mod) % mod;
	            
	            inclusive[i] = k;
	            hm[s[i] - 97] = i;
	        }
	        exclusive[i] = (inclusive[i+1] + exclusive[i+1]) % mod;
	    }
	    
	    return (inclusive[0] + exclusive[0] + 1) % mod;
	}
};