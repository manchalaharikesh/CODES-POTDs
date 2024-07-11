// DATE: 09-JUL-2024
// Question URL: https://www.geeksforgeeks.org/problems/three-sum-closest/1
// Question: Closest Three Sum
// Description: Given an array, arr of integers, and another number target, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

//              Note: If there are multiple solutions, return the maximum one.
// Approach: 1. Here as we need to find the triplet sum which gives closest sum to the target, we need to sort the array.
//              Then for every ith element (to be an element of the answer) in array we have to search in [i+1, n-1] array for other two elements. To do this optimally we use two pointer approach (p1 at i+1, p2 at n-1 initially).
//              Here p1 and p2 are moved optimally as the array is sorted and always ensured to move in such a way the sum is further closer to the target (to understand please refer to two pointer approach code below).
//              Thus this solution has a time complexity of O(N^2).
//              Please refer to code for understanding the edge cases.

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
        int p1, p2, sum, ans = INT_MIN, _min = INT_MAX;
        
        for(int i = 0; i < arr.size()-2; i++){
            p1 = i+1, p2 = arr.size()-1;
            
            while(p1 < p2){
                sum = arr[i] + arr[p1] + arr[p2];
                if(sum == target) return target;
                if(abs(target - sum) == _min){
                    ans = max(ans, sum);
                }
                else if(abs(target - sum) < _min){
                    _min = abs(target - sum);
                    ans = sum;
                }
                
                if(sum < target) p1++;
                else p2--;
            }
        }
        
        return ans;
    }
};