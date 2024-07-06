// DATE: 06-JUL-2024
// Question URL: https://leetcode.com/problems/pass-the-pillow/

// Question: 2582. Pass the Pillow
// Description: There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

//              For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
//              Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

// Approach: 1. As there are n people and passing the pillow is reversed upon reaching the ends, to say who has the pillow at time t, we must know the direction of passing the pillow.
//              For n people in the queue, after every n-1 passes the direction of passing pillow changes.
//              Here, time / (n-1), gives the number of full iterations completed.
//              The direction is given by (time / (n-1)) % 2, if this is even - passing is going from 1 to N, otherwise from N to 1.
//              Then relative to the direction, time % (n-1) is the instance who has pillow at that instance of time.
//              If pillow is moving from 1 to N, 1 + time % (n-1) gives the answer, while for the reverse n - (time % (n-1)) gives the answer.
//              Dry Run code for better understanding.

class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = time / (n-1);

        if(dir % 2){
            return n - (time % (n-1));
        }

        return 1 + time % (n-1);
    }
};