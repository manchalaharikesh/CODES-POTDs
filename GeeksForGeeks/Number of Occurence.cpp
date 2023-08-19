// DATE: 20-AUG-2023
// Question URL: https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

// Question: Number of Occurence
// Description: For a given sorted array of size 'N' and an integer x find the number of occurences of the integer x. 
// Approach: 1. Iterate through the array and count the occurences of the given integer x TC: O(N).
// *(optimal)2. Implement two pointer concept with binary search to find the start and end indices of the integer x TC: O(log(N)).

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int p1 = -1, p2 = -1;
	    solve(arr, x, 0, n-1, p1, p2);

 	    return p1 == p2 ? p1 == -1 ? 0 : 1 : p2 - p1 + 1; 
	}
	
	void solve(int arr[], int x, int low, int high, int& p1, int& p2){
	    if(low > high) return;
	    
	    int mid = low + (high - low)/2;
	    if(arr[mid] == x){
	        if(p1 == -1){
	            p1 = mid;
	            p2 = mid;
                solve(arr, x, low, mid-1, p1, p2);
                solve(arr, x, mid+1, high, p1, p2);
	        }
	        else if(mid < p1){
	            p1 = mid;
	            solve(arr, x, low, mid-1, p1, p2);
	        }
	        else if(mid > p2){
	            p2 = mid;
	            solve(arr, x, mid+1, high, p1, p2);
	        }
	    }
	    else if(arr[mid] < x){
	        solve(arr, x, mid+1, high, p1, p2);
	    }
	    else{
	        solve(arr, x, low, mid-1, p1, p2);
	    }
	}
};