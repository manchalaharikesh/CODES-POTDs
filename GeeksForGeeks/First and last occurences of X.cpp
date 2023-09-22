// DATE: 22-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
// Question: First and last occurences of X
// Description: For a given sorted array arr and integer X, return the indices of first and last occurences of X in array. If no such element is present return -1 for both the index positions.
// Approach: 1. As the array is sorted implement two pointer approach TC: O(N).
//           2. Implement binary search to point the pointers to the start and end positions of the element X TC: O(log(N)).

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