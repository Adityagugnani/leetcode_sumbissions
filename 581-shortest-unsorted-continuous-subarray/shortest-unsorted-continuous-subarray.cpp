class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int f = INT_MAX;
        int s = -1;

        stack<pair<int, int>>st;

        // First pass: Left to Right
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first > nums[i]){
                f = min(f, st.top().second);
                s = i;
                st.pop();
            }
            st.push({nums[i], i});
        }

        // Clear the stack for second pass
        while(!st.empty()) st.pop();

        // Second pass: Right to Left
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top().first < nums[i]){
                s = max(s, st.top().second);
                f = min(f, i);
                st.pop();
            }
            st.push({nums[i], i});
        }

        if(f != INT_MAX) return s - f + 1;
        return 0;
    }
};