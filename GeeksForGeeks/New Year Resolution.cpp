// DATE: 31-DEC-2023
// Question URL: https://www.geeksforgeeks.org/problems/good-by-2023/1

// Question: New Year Resolution
// Description: As the clock struck midnight on New Year's Eve, Geek bid farewell to the wasted moments of 2023, realizing the untapped potential of GFG's Problem of the Day.

//              His 2024 resolution: Solve POTD every day.
//              Eager to earn coins for GFG Merchandise, Geek faces new rules:

//              Earning Coin: Geek can accumulate coins[i] by solving the POTD on the ith day, where 1 <= coins[i] <= 2024 and the sum of coins <= 2024.
//              Merchandise Eligibility: To purchase merchandise, the coins earned must be divisible by 20 or 24, or precisely equal to 2024.
//              Geek's resolutions often fades over time. Realistically, he can only commit to active participation for N (where N ≤ 366) days. Given the value of N and number of coins associated with each POTD, can Geek strategically solve some (or all) POTDs to become eligible for redeeming merchandise?
// Approach: 1. Brute Force.

class Solution {
    
    public:
    bool solution(int i,int n, int coins[], int sum){
        if((sum == 2024 || sum % 20 == 0 || sum % 24 == 0) && sum != 0) return true;
        for(; i < n; i++){
            sum += coins[i];
            if(solution(i+1, n, coins, sum)) return true;
            sum -= coins[i];
            if(solution(i+1, n, coins, sum)) return true;
        }
        return false;
    }
    int isPossible(int N , int coins[]) 
    {
        return solution(0, N, coins, 0);
    }
    
};