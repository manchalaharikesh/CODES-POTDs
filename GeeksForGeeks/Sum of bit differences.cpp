// DATE: 29-FEB-2023
// Question URL: https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1
// Question: Sum of bit differences
// Description: Given an array integers arr[], containing n elements, find the sum of bit differences between all pairs of element in the array. Bit difference of a pair (x, y) is the count of different bits at the same positions in binary representations of x and y.
//              For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 respectively and the first and last bits differ between the two numbers.

//              Note: (x, y) and (y, x) are considered two separate pairs.
// Approach: 1. For 0 <= i < 32 bits get count of numbers that are having set bit and unset bit at i. Then ans = ans + set*unset. The final ans is 2*ans.

class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    long long ans = 0;
	    long long int ones = 0, zeros = 0;
	    
	    for(int i = 0; i < 32; i++){
	        ones = 0;
	        zeros = 0;
	        for(int j = 0; j < n; j++){
	            if((1 << i) & arr[j]) ones++;
	            else zeros++;
	        }
	        
	        ans = ans + ones*zeros;
	    }
	    
	    return 2*ans;
	}
};