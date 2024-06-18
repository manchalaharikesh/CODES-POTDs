// DATE: 18-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/rectangles-in-a-circle0457/1

// Question: Number of Rectangles in a Circle
// Description: Given a circular sheet of radius, r. Find the total number of rectangles with integral length and width that can be cut from the sheet that can fit on the circle, one at a time.
// Approach: 1. For a rectangle to fit inside a circle, the maximum size of diagonal of the rectangle can be of the diameter of the circle.
//              Using this we find all possibilities of length and breadth where l*l + b*b <= d*d for l, j in [1, d) where d = 2*r.

class Solution {
  public:
    int rectanglesInCircle(int r) {
        int d = 2*r, ans = 0;
        
        for(int l = 1; l < d; l++){
            for(int b = 1; b < d; b++){
                if(l*l + b*b <= d*d) ans++;
            }
        }
        
        return ans;
    }
};