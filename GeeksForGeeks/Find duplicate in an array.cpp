// DATE: 24-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
// Question: Find duplicate in an array
// Description: For a given array of size N, all the elements are in the range 0 to N-1, find the duplicate elements and return in ascending order.
// Approach: 1. Store the freq of elements in a count array, then use it to find duplicates TC: O(N), SC: O(N).

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> count(n, 0);
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            count[arr[i]]++;
        }
        
        for(int i = 0; i < n; i++){
            if(count[i] > 1){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0) ans.push_back(-1);
        
        return ans;
    }
};