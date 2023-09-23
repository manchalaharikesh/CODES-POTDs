// DATE: 22-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

// Question: Equilibrium Point
// Description: For a given array find the position of where the sum of elements to its right is equal of sum of elements to is left, If not possible return -1.
// Approach: 1. Brute Force iterative approach TC: O(N).

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        int sum = 0, sum_so_far = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];
        }
        
        for(int i = 0; i < n; i++){
            if(sum_so_far == sum-a[i]) return i+1;
            else{
                sum_so_far += a[i];
                sum -= a[i];
            }
        }
        return -1;
    }

};