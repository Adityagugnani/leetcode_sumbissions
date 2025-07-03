class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) swap(nums1, nums2);
        int m = nums1.size(), n = nums2.size(), ans = 0;
        vector<int> dp(n + 1);
        for (int i = 1; i <= m; ++i) {
            for (int j = n; j >= 1; --j) {
                dp[j] = (nums1[i - 1] == nums2[j - 1]) ? dp[j - 1] + 1 : 0;
                ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};