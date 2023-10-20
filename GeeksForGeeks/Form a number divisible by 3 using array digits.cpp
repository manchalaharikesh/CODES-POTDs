// DATE: 20-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/form-a-number-divisible-by-3-using-array-digits0717/1
// Question: Form a number divisible by 3 using array digits
// Description: You will be given an array arr of integers of length N. You can construct an integer from two integers by treating the integers as strings, and then concatenating them. For example, 19 and 4 can be used to construct 194 and 419.

//              The task is to find whether it’s possible to construct an integer using all the digits of these numbers such that it would be divisible by 3.
//              If it is possible then print 1 and if not print 0.
// Approach: 1. If arr[i] + c is divisible by 3 continue else store remainder in c. At the end return c == 0.

class Solution {
  public:
    int isPossible(int N, int arr[]) {
        int sum = 0, c = 0;
        
        for(int i = 0; i < N; i++){
            if((arr[i] + c) % 3 == 0){
                c = 0;
            }
            else{
                c = (arr[i] + c) % 3;
            }
        }
        
        return c == 0;
    }
};