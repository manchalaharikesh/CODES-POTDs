// DATE: 05-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1
// Question: Count number of substrings
// Description: For a given string s, find the number of count of substrings with exactly k distinct characters.
// Approach: 1. BRUTE FORCE.
//           2. fill kdp i.e., for kdp[i] = j we get kth distinct character for s[i] at s[j] for all valid i.

class Solution
{
  public:
    long long int substrCount (string s, int k) {
        long long int ans = 0;
        int count1[26] = {0}, count2[26] = {0}, dis = 0, p1 = 0, p2 = 0;
        int n = s.length();
        vector<int> kdp(n, -1);
        bool flag = false;
        
        // fill kdp i.e., for kdp[i] = j we get kth distinct character for s[i] at s[j] for all valid i
        while(p1 < n){
            dis = dis + (count1[s[p2] - 97] == 0 ? 1 : 0);
            count1[s[p2] - 97]++;
            
            while(dis == k){
                kdp[p1] = p2;
                count1[s[p1] - 97]--;
                if(count1[s[p1] - 97] == 0) dis--;
                p1++;
            }
            
            if(p2 < n - 1) p2++;
            else p1++;
        }
        
        if(kdp[0] == -1) return 0;
        
        p1 = 0;
        p2 = 0;
        dis = 0;
        
        while(p1 < n){
            // encountered for the first time
            dis = dis + (count2[s[p2] - 97] == 0 ? 1 : 0);
            count2[s[p2] - 97]++;

            if(dis <= k && p2 < n-1) p2++;
            else if(dis >= k){
                flag = false;
                if(dis > k){
                    dis--;
                    count2[s[p2] - 97]--;
                    p2--;
                    flag = true;
                }
                
                while(dis == k){
                    ans = ans + (p2 - kdp[p1] + 1);
                    count2[s[p1] - 97]--;
                    if(count2[s[p1] - 97] == 0) dis--;
                    p1++;
                }
                if(flag) p2++;
            }
            else p1++;
        }
        
        return ans;
    }
};