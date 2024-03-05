// DATE: 05-MAR-2024
// Question URL: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/

// Question: 1750. Minimum Length of String After Deleting Similar Ends
// Description: Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

//				Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
//				Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
//				The prefix and the suffix should not intersect at any index.
//				The characters from the prefix and suffix must be the same.
//				Delete both the prefix and the suffix.
//				Return the minimum length of s after performing the above operation any number of times (possibly zero times).
// Approach: 1. In a two pointer approach when s[p1] == s[p2] means found same char on extremes move p1 forward and p2 backward until same char is found at those edges. Repeat it until the extremes are same. Final return the distance between p1 and p2.

func minimumLength(s string) int {
    var p1, p2 int = 0, len(s)-1
    var prev byte

    for p1 < p2 && s[p1] == s[p2] {
        prev = s[p1]
        for prev == s[p1] && p1 != p2{
            p1++
        }

        prev = s[p2]
        for prev == s[p2] && p1 != p2 {
            p2--
        }
    }

    if p1 == p2 && p1 != 0 && s[p1-1] == s[p1]{
        return 0
    }
    return p2 - p1 + 1
}