class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int freq[5001] = {0}, n = nums.size();
        for (int pos = 0; pos < n; ++pos) ++freq[nums[pos]];
        int i = 5000;
        for (int pos = 1; pos < n; pos += 2) {
            while (freq[i] == 0) --i;
            nums[pos] = i;
            --freq[i];
        }
        for (int pos = 0; pos < n; pos += 2) {
            while (freq[i] == 0) --i;
            nums[pos] = i;
            --freq[i];
        }
    }
};