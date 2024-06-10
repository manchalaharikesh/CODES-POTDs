// DATE: 10-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

// Question: Nuts and Bolts Problem
// Description: Given a set of n nuts & bolts. There is a one-on-one mapping between nuts and bolts. You have to Match nuts and bolts efficiently. Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means the nut can only be compared with the bolt and the bolt can only be compared with the nut to see which one is bigger/smaller.
//              The elements should follow the following order: { !,#,$,%,&,*,?,@,^ }

//              Note: Make all the required changes directly in the given arrays, output will be handled by the driver code.
// Approach: 1. We need to sort both nuts and bolts with respect to the order of characters present in the array specified { !,#,$,%,&,*,?,@,^ }.
//              So, we store the values of nuts into a map, then we iterate over the string "!#$%&*?@^" for order of preference of characters.
//              Now, we parallely check if that particular character is in map, if so insert it into nuts starting from 0 and finally copy it to bolts.
//              TC: O(n), SC: O(N)
//           2. We can see the given order of characters has increasing order of ASCII values thus we can simply sort both nuts and bolts.
//              TC: O(N*log(N)), SC: O(N) (stack space for sorting)

class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        map<int, int> m;
        string s = "!#$%&*?@^";
        int k = 0;
        
        for(int i = 0; i < n; i++){
            m[nuts[i]] = 1;
        }
        
        for(int i = 0; i < s.length(); i++){
            if(m.find(s[i]) != m.end()){
                nuts[k] = s[i];
                k++;
            }
        }
        
        for(int i = 0; i < n; i++){
            bolts[i] = nuts[i];
        }
    }
};