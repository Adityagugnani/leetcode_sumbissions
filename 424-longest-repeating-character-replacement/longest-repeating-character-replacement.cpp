class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int left = 0;
        int right =0;
        int maxcount =0;
        int maxlength=0;
        for(right =0;right<s.length();right++){
            freq[s[right] - 'A']++;
            maxcount = max(maxcount,freq[s[right] - 'A']);
            while((right-left+1)-maxcount>k){
                freq[s[left] - 'A']--;
                left++;
            }
            maxlength = max(maxlength, right - left + 1);
        }
        return maxlength;
    }
};