// DATE: 27-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1
// Question: Find the closest pair from two arrays
// Description: For given two sorted arrays arr, brr and an integer x, find the pair with each element from each array whose sum is closest to x.
// Approach: 1. Two pointer concept by having p1 at 0 of arr and p2 at brr.size()-1.

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int> ans;
        int val = 0, diff = INT_MAX, sum = 0;
        int p1 = 0, p2 = m-1;
        
        while(p1 < n && p2 >= 0){
            sum = arr[p1] + brr[p2];
            if(sum == x){
                val = arr[p1] + brr[p2];
                break;
            }
            else if(diff > abs(sum - x)){
                diff = abs(sum - x);
                val = sum;
            }
            
            if(sum < x) p1++;
            else p2--;
        }
        
        ans.push_back(val);
        
        return ans;
    }
};