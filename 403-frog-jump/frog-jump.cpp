class Solution {
public:
    bool ans(vector<int>&stones, int i, int k, vector<vector<int>>&dp){
        if(i==stones.size()-1){
            return true;
        }
        if (k < 0) return false;
        if(i>=stones.size()){
            return false;
        }
        if (dp[i][k] != -1) return dp[i][k];
        bool valid = false;
        int st = i+1;
        int end = stones.size()-1;
        int mid = -1;
// position of next stone to jump on 
        while(st<=end){
            mid = st+(end-st)/2;
            if(stones[mid]==stones[i]+k){
                 valid = true;
                 break;
            }else if (stones[mid]>stones[i]+k){
                end = mid-1;
            }else{
                st = mid+1; 
            }
        }
// finding all possible way to jump by k || k-1 || k+1 variable 
        if (valid && mid != -1) {
            if (ans(stones, mid, k - 1, dp) || ans(stones, mid, k, dp) || ans(stones, mid, k + 1, dp)) {
                return dp[i][k] = 1;
            }
        }
        return dp[i][k] = 0;
    }
    bool canCross(vector<int>& stones) {
         int n = stones.size();
// using memoization to stop TLE
        vector<vector<int>>dp(n, vector<int>(n + 1, -1));
        if (stones[1] != 1) return false;
        return ans(stones, 0, 1, dp);
    }
};