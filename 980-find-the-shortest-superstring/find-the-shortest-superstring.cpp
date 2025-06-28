class Solution {
    vector<vector<string>> req;
    string merge(string &a, string &b) // a is followed by b (ab)
    {
        int n=a.size(), m=b.size(), len=1, idx=0;
        while(len<=min(n, m))
        {
            if(a.substr(n-len)==b.substr(0, len))
            {
                idx=len;
            }
            len++;
        }
        string res=b.substr(idx);
        return res;
    }
    string solve(vector<string> &words, int prev, int mask, int n, vector<vector<string>> &dp)
    {
        if(dp[prev][mask]!="") return dp[prev][mask];
        string res="";
        int minLen=INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(mask&(1<<i)) continue;
            string temp=req[prev][i]+solve(words, i, mask|(1<<i), n, dp);
            if(temp.size()<minLen)
            {
                minLen=temp.size();
                res=temp;
            }
        }
        return dp[prev][mask]=res;
    }
public:
    string shortestSuperstring(vector<string>& words) 
    {
        int n=words.size();
        req.resize(n, vector<string> (n, ""));
        vector<vector<string>> dp(n, vector<string> ((1<<(n+1)), ""));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j) continue;
                req[i][j]=merge(words[i], words[j]);
            }
        } 
        string ans="";
        int minLen=INT_MAX;
        int mask=0;
        for(int i=0; i<n; i++)
        {
            string temp=words[i]+solve(words, i, mask|(1<<i), n, dp);
            if(temp.size()<minLen)
            {
                minLen=temp.size();
                ans=temp;
            }
        } 
        return ans;
    }
};