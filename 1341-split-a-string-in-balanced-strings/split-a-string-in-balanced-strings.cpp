class Solution {
public:
    int balancedStringSplit(string s) {
        int lc = 0 , rc = 0;
        int ans = 0;
        for(auto x : s){
            if(x == 'R')
            rc++;
            else
            lc++;

            if(lc == rc){
                ans++;
                lc = 0;
                rc = 0;
            }
        }
        return ans;
    }
};