// DATE: 20-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1
// Question: Modular Exponentiation for large numbers
// Description: Implement pow(x, n) % M.
//              In other words, for a given value of x, n, and M, find  (x^n) % M.
// Approach: 1. It is done using the bit manipulations based method to find bth power of a (i.e., a^b).
//              This can be easily explained using, let a = 3, b = 7, a^b => (a^1)*(a^2)*(a^4) as 7 has 0, 1, 2 positions as its set bits.
//              This approach takes exploring only log2(b) time as we only explore until MSB in b not until b.

class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    long long int ans = 1, mul = x;
		    
		    for(int i = 0; i <= log2(n); i++){
		        if(n & (1 << i)){
		            ans = ((ans%M)*(mul%M))%M;
		        }
		        mul = ((mul%M)*(mul%M))%M;
		    }
		    
		    return ans;
		}
};