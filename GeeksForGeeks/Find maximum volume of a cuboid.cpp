// DATE: 19-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/magical-box5306/1
// Question: Find maximum volume of a cuboid
// Description: You are given a perimeter & the area. Your task is to return the maximum volume that can be made in the form of a cuboid from the given perimeter and surface area.
//              Note: Round off to 2 decimal places and for the given parameters, it is guaranteed that an answer always exists.
// Approach: 1. From geometry to get maximum volume then using partial derivatives we deduce l= ((perimeter-sqrt(perimeter ^2 - 24*area))/12), w = l, h = ((perimeter/4)-2*l).

class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        double l = (perimeter - sqrt(perimeter*perimeter - 24*area))/12;
        double h = perimeter/4 - l - l;
        
        cout << l << " " << l << " " << h << "\n";
        return l*l*h;
    }
};