// DATE: 04-MAR-2024
// Question URL: https://leetcode.com/problems/bag-of-tokens/description/

// Question: 948. Bag of Tokens
// Description: You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] donates the value of tokeni.

//				Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

//				Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
//				Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
//				Return the maximum possible score you can achieve after playing any number of tokens.
// Approach: 1. Sort the values initially, with two pointers p1 and p2 at 0, n-1 respectively, until power is enough face-up using p1 incrementally. If power is not enough check if face-down at p2 makes impact. If yes face-down and add power else stop.

func bagOfTokensScore(tokens []int, power int) int {
    sort.Slice(tokens, func (i int, j int) bool {return tokens[i] < tokens[j]})
    var p1, p2, score int = 0, len(tokens)-1, 0

    for p1 <= p2 {
        if power >= tokens[p1] {
            score++
            power = power - tokens[p1]
            p1++
        } else if score > 0 && p1 != p2 && power + tokens[p2] >= tokens[p1]{
            power = power + tokens[p2]
            score--
            p2--
        } else {
            break
        }
    }

    return score
}