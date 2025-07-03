class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        
        unordered_map<char, int> s1Count;
        unordered_map<char, int> s2Count;
        
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i]]++;
            s2Count[s2[i]]++;
        }
        
        if (s1Count == s2Count) {
            return true;
        }
        
        int left = 0;
        for (int right = s1.length(); right < s2.length(); right++) {
            s2Count[s2[right]]++;
            s2Count[s2[left]]--;
            
            if (s2Count[s2[left]] == 0) {
                s2Count.erase(s2[left]);
            }
            
            left++;
            
            if (s1Count == s2Count) {
                return true;
            }
        }
        
        return false;        
    }
};