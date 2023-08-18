// DATE: 18-AUG-2023
// Question URL: https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

// Question: Leaders in an Array
// Description: For a given array of size 'N' print all the elements that have all the elements smaller than it to its right.
// Approach: 1. Iterate from the end and store the maximum you have reached so far at each pass.
//           2. If you are updating the maximum at a point print the value as it is maximum for all the elements including itself and towards its right.

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        int max_so_far = a[n-1];
        vector<int> v;
        for(int i = n-1; i >= 0; i--){
            if(a[i] >= max_so_far){
                v.push_back(a[i]);
                max_so_far = a[i];
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};