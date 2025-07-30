class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(!n) return 0;
        int left = 0, right = n - 1, res = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(citations[mid] < n - mid) left = mid + 1;
            else{
                res = n - mid;
                right = mid - 1;
            }
        }
        return res;
    }
};