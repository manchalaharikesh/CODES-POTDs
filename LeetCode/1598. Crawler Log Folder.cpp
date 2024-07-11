// DATE: 10-JUL-2024
// Question URL: https://leetcode.com/problems/crawler-log-folder/description/

// Question: 1598. Crawler Log Folder
// Description: The Leetcode file system keeps a log each time some user performs a change folder operation.

//              The operations are described below:

//              "../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
//              "./" : Remain in the same folder.
//              "x/" : Move to the child folder named x (This folder is guaranteed to always exist).
//              You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

//              The file system starts in the main folder, then the operations in logs are performed.

//              Return the minimum number of operations needed to go back to the main folder after the change folder operations.
// Approach: 1. For every "../" we decrease the tree depth or log depth (by moving back), "./" we survive in the same depth (by being in same log), otherwise we are increase our log depth (by moving to child log).
//              Further from here the code is self explanatory.

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int d = 0;

        for(int i = 0; i < logs.size(); i++){
            if(logs[i] == "../") d = max(d-1, 0);
            else if(logs[i] == "./") continue;
            else d++;
        }

        return d;
    }
};