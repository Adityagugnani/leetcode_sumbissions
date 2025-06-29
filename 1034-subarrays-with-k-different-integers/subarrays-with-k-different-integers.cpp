class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subprob(nums, k) - subprob(nums, k - 1);
    }
    int subprob(vector<int>& nums, int k) {
        int l = 0, r = 0, count = 0, ans = 0;
        int freq[20001] = {0};
        while (r < nums.size()) {
            if (freq[nums[r++]]++ == 0) {
                count++;
            }
            while (count > k) {
                freq[nums[l]]--;
                if (!freq[nums[l++]]) {
                    count--;
                }
            }
            ans += r - l;
        }
        return ans;
    }
};