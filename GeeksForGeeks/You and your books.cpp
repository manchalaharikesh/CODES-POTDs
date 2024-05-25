// DATE: 25-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/you-and-your-books/1
// Question: You and your books
// Description: You have n stacks of books. Each stack of books has some nonzero height arr[i] equal to the number of books on that stack ( considering all the books are identical and each book has a height of 1 unit ). In one move, you can select any number of consecutive stacks of books such that the height of each selected stack of books arr[i] <= k. Once such a sequence of stacks is chosen, You can collect any number of books from the chosen sequence of stacks.
//              What is the maximum number of books that you can collect this way?
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        long long ans = 0, s = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] <= k){
                s = s + arr[i];
                if(s > ans) ans = s;
            }
            else{
                s = 0;
            }
        }
        
        return ans;
    }
};