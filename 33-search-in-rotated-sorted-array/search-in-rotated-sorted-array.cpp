class Solution {
public:
    int findPivotIndex(vector<int>&nums,int n){
        int l=0;
        int r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return r;
    }

    int binarySearch(int l,int r,vector<int>&nums,int target){
        int idx=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                idx=mid;
                break;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return idx;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot_index= findPivotIndex(nums,n);
        int idx=-1;
        idx=binarySearch(0,pivot_index-1,nums,target);
        if(idx!=-1){
            return idx;
        }
        idx=binarySearch(pivot_index,n-1,nums,target);
        return idx;
    }
};