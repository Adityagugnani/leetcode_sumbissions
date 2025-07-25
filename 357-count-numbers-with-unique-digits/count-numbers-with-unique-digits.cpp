class Solution {
private:
    int countUniqueDigits(char pos, short used, const char& len, vector<vector<int>>& dp){
        if(pos == len){
            return 1;
        }
        if(dp[pos][used] != -1){
            return dp[pos][used];
        }

        int cnt = 0;
        for(char d = !pos; d <= 9; d++){
            short setBit = 1 << d;
            if(used & setBit){
                continue;
            }
            cnt += countUniqueDigits(pos + 1, used | setBit, len, dp);
        }
        return dp[pos][used] = cnt;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        int cnt = 1;

        for(char len = 1; len <= n; len++){
            vector<vector<int>> dp(len + 1, vector<int>(1024, -1));
            cnt += countUniqueDigits(0, 0, len, dp);
        }
        return cnt;
    }
};