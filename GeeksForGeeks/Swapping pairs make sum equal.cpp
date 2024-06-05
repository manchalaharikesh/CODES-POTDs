// DATE: 05-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1

// Question: Swapping pairs make sum equal
// Description: Given two arrays of integers a[] and b[] of size n and m, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

//              Note: Return 1 if there exists any such pair otherwise return -1.
// Approach: 1. In this approach the problem can be summarized into a simple mathematical equation.
//              Let's consider u, v be the sum of elements of a[] and b[] respectively. Then we need to find p, q from a[], b[] respectively.
//              Such that, u - p + q == v - q + p. This is nothing but for each p from a[] we get a q = (v - 2*p - u)/2 and we try to find if this q exists in b and also we need to check if u + 2*q = v + 2*p (as q might be a truncated value due to division by 2).

class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int u = 0, v = 0, q;
        map<int, int> h;
        
        for(int i = 0; i < n; i++){
            u += a[i];
        }
        
        for(int i = 0; i < m; i++){
            v += b[i];
            h[b[i]]++;
        }
        
        // u + 2*q == v + 2*p
        for(int i = 0; i < n; i++){
            q = (v + 2*a[i] - u)/2;
            if(h.find(q) != h.end() && u - a[i] + q == v - q + a[i]){ 
                return 1;
            }
        }
        
        return -1;
    }
};