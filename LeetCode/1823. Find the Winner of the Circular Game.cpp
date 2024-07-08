// DATE: 08-JUL-2024
// Question URL: https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

// Question: 1823. Find the Winner of the Circular Game
// Description: There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

//              The rules of the game are as follows:

//              Start at the 1st friend.
//              Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.
//              The last friend you counted leaves the circle and loses the game.
//              If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
//              Else, the last friend in the circle wins the game.
//              Given the number of friends, n, and an integer k, return the winner of the game.
// Approach: 1. Remove every kth number in circular fashion from the vector until only one element is left.
//              Please refer to code for better understanding.

class Solution {
public:
    int solve(vector<int>& players, int n, int k, int idx){
        if(n == 1){
            return players[0];
        }

        idx = (idx + k - 1) % n;
        players.erase(players.begin() + idx);
        return solve(players, n-1, k, idx);
    }
    int findTheWinner(int n, int k) {
        vector<int> players;
        int s = 0;    

        for(int i = 1; i <= n; i++){
            players.push_back(i);
        }

        return solve(players, n, k, 0);
    }
};