// DATE: 14-JUL-2024
// Question URL: https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1
// Question: Segregate 0s and 1s
// Description: Given an array arr consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.
// Approach: 1. This solution uses a two pointer approach, we have p1 at 0 and p2 at n-1.
//              We move p1 to the right and p2 to the left untl p1 < p2.
//              We move p1 to the first instance (to the right from current position) where arr[p1] == 1 and p2 to the first instance (to the left from curr position) where arr[p2] == 0 and then swap them and continue the same until p1 < p2.
//              Please refer to code for better understanding.

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int p1 = 0, p2 = arr.size()-1;
        
        while(p1 < p2){
            while(p1 < p2 && arr[p1] == 0) p1++;
            while(p2 > p1 && arr[p2] == 1) p2--;
            
            if(p1 < p2 && arr[p1] == 1 && arr[p2] == 0){
                arr[p1] = 0;
                arr[p2] = 1;
                
                p1++;
                p2--;
            }
        }
    }
};