class Solution {
public:
    bool dfs(int i, int j, string&s, string&p, vector<vector<int>>&dp){
        if (i == 0 && j == 0) 
            return true;          // both empty
        if (j == 0) 
            return false;         // pattern empty, text not
        if (i == 0) {
            // text empty, pattern nonempty → only match if pattern is a*b*c*…
            if (j % 2 == 1) 
                return false;
            for (int k = 2; k <= j; k += 2) {
                if (p[k-1] != '*') 
                    return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j]; 
        
        
        if(p[j-1] == '*') {
            dp[i][j] = dfs(i, j-2, s, p, dp);
            if(!dp[i][j] && (p[j-2] == '.' || p[j-2] == s[i-1])) 
                dp[i][j] = dfs(i-1, j, s, p, dp);
        }
        else if(p[j-1] == s[i-1] || p[j-1] == '.') dp[i][j] = dfs(i-1, j-1, s, p, dp);
        else dp[i][j] = false;
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return dfs(n, m, s, p, dp);
    }
};