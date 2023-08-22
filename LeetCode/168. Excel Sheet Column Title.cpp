class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while(columnNumber != 0){
            int rem = columnNumber % 26;
            ans = char(64 + (rem == 0 ? 26 : rem)) + ans;
            if(rem == 0) columnNumber--;
            columnNumber /= 26;
        }

        return ans;
    }
};