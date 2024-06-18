// DATE: 17-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/check-if-two-line-segments-intersect0017/1
// Question: Check If two Line segments Intersect
// Description: Given the coordinates of the endpoints(p1,q1, and p2,q2) of the two line segments. Check if they intersect or not. If the Line segments intersect return true otherwise return false.

//              Note: Please check the intersection lies within the line segments.
// Approach: 1. Code is Self-Explanatory.

class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        float m1, m2;
        float x, y;
        bool per1 = false, per2 = false;
        
        if(p1[0] == q1[0]){ 
            m1 = 0;
            per1 = true;
        }
        else m1 = (q1[1] - p1[1]) / (float)(q1[0] - p1[0]);
        
        if(p2[0] == q2[0]){ 
            m2 = 0;
            per2 = true;
        }
        else m2 = (q2[1] - p2[1]) / (float)(q2[0] - p2[0]);
        
        if(m1 == m2){ 
            // lines parallel to y-axis slope tan90
            if(per1 && per2){
                return p1[0] == p2[0] ? "true" : "false";
            }
            else if(!per1 && !per2 && m1 == 0){
                return p1[1] == p2[1] ? "true" : "false";
            }
            else{ // m != 0
                if(p2[1] - p1[1] - m1 * (p2[0] - p1[0]) == 0){ // check if lines are collinear or else just parallel
                    // check if these collinear lines are intersecting each other (one line on another)
                    if(p1[0] <= p2[0] && q1[0] >= p2[0] || p1[0] <= q2[0] && q1[0] >=q2[0]) return "true";
                    else if(p2[0] <= p1[0] && q2[0] >= p1[0] || p2[0] <= q1[0] && q2[0] >=q1[0]) return "true";
                }
                
                return "false";
            }
        }

        // (y - y1) = m1 * (x - x1);
        // (y - y2) = m2 * (x - x2);
        // y1 + m1 * (x - x1) = y2 + m2 * (x - x2)
        // m1*x - m1*x1 - m2*x + m2*x2 = y2 - y1
        // x*(m1 - m2) = (y2 - y1) + m1*x1 - m2*x2
        // x = ((y2-y1)+(m1*x1 - m2*x2))/(m1 - m2)
        
        x = per1 ? p1[0] : per2 ? p2[0] : ((p2[1] - p1[1]) + (m1*p1[0] - m2*p2[0]))/(m1-m2);
        y = p1[1] + m1 * (x - p1[0]);
    
        // cout << x << "=" << "((" << p2[1] << "-" << p1[1]<<") +" << "(" << m1 << "*" << p1[0] << "-" << m2 << "*" << p2[0] << "))/(" << m1 << "-" << m2 << ")\n";
        // cout << m1 << " " << a1 << " " << b1 << "\n";
        // cout << m2 << " " << a2 << " " << b2 << "\n";
        
        // cout << a1 * b1 << " " << a2 * b2 << "\n";
        
        // cout << x << " " << y << "\n";
        
        if(min(p1[0], q1[0]) <= x && x <= max(p1[0], q1[0]) && min(p1[1], q1[1]) <= y && y <= max(p1[1], q1[1])){
            if(min(p2[0], q2[0]) <= x && x <= max(p2[0], q2[0]) && min(p2[1], q2[1]) <= y && y <= max(p2[1], q2[1])){
                return "true";
            }
        }
        
        return "false";
    }
};