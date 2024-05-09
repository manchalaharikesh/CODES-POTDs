// DATE: 09-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/divisor-game-1664432414/1

// Question: Divisor Game
// Description: Alice and Bob take turns playing a game, with Alice starting first.
//              Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

//              Choosing any x with 0 < x < n  and n % x == 0.
//              Replacing the number n on the chalkboard with n - x.
//              Also, if a player cannot make a move, they lose the game.
//              Return true if and only if Alice wins the game, assuming both players play optimally.
// Approach: 1. As both players play optially we initially try to understand the pattern in this game theory question.
//              Lets say n = 1, and as there is no x possible alice loss the game (when n = 1 with alice losses the game).
//              Lets say n = 2, and as there is only one x = 1 possible alice make n = 2 - 1 = 1 thus as opponent gets 1 alice wins the game (so when n = 2 with alice gets 2 he wins).
//              Lets say n = 3, and there is only one x = 1 possible alice make n = 3 - 1 = 2 thus opponent gets 2 and alice losses the game (so when n = 3 with alice he losses the game).
//              Lets say n = 4, and there are two possibilities for x = 1, 2 if we use x = 1 ? n -> 3 : n -> 2. So as opponent should loose he must be given n = 3.
//              By above pattern we can say for every n % 2 == 0 we can optimally play such that alice will always wins.

class Solution {
  public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};