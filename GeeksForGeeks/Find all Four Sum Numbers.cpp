// DATE: 26-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
// Question: Find all Four Sum Numbers
// Description: For a given array of integers and a target sum k, find the quadruplets that make up the sum equal to k.
// Approach: 1. Sort the array, then by choosing two numbers ith, jth using for loop fix the other two using the two pointer technique. Repeat the same for all possible ith and jth numbers.

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                int req_sum = k - arr[i] - arr[j];
                int p1 = j+1, p2 = n-1;
                while(p1 < p2){
                    if(req_sum == arr[p1] + arr[p2]){
                        s.insert({arr[i], arr[j], arr[p1], arr[p2]});
                        p1++;
                        p2--;
                    }
                    else if(req_sum > arr[p1] + arr[p2]) p1++;
                    else if(req_sum < arr[p1] + arr[p2]) p2--;
                }
            }
        }
        
        for(auto itr = s.begin(); itr != s.end(); itr++){
            ans.push_back(*itr);
        }
        
        return ans;
    }
};