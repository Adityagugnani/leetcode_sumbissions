int t[2001][2001];
int pal[2001][2001];
class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        if (i >= j) return true;
		if (pal[i][j] != -1) return pal[i][j];
		if (s[i] == s[j]) return pal[i][j] = isPalindrome(s, i + 1, j - 1);
		return pal[i][j] = false;
    }
    int solve(string& s, int i, int j){
        if(i >= j || isPalindrome(s, i, j)) return 0;
        if(t[i][j] != -1) return t[i][j];
        int res = INT_MAX;
        for(int k = i; k <= j-1; k++){
            if (isPalindrome(s, i, k)) {
                int right = (t[k+1][j] != -1) ? t[k + 1][j] : 
                (t[k + 1][j] = solve(s,k + 1,j));
                res = min(res, 1 + right);
            }
        }
        return t[i][j] = res;
    }
    int minCut(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        memset(pal, -1, sizeof(pal));
        return solve(s, 0, n-1);
    }
};