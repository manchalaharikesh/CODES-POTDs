// DATE: 23-DEC-2023
// Question URL: https://leetcode.com/problems/path-crossing/description/

// Question: 1496. Path Crossing
// Description: Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
//              Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

// Approach: 1. Store coordinates of each instance of position in a map.

class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int, int>, int> m;
        int x = 0, y = 0;
        int size = path.length();

        m.insert({pair<int, int>(0, 0), 1});

        for(int i = 0; i < size; i++){
            if(path[i] == 'N') y++;
            else if(path[i] == 'S') y--;
            else if(path[i] == 'E') x++;
            else x--;

            pair<int, int> p;
            p.first = x;
            p.second = y;

            if(m.find(p) == m.end()) m.insert({p, 1});
            else return true;
        }

        return false;
    }
};