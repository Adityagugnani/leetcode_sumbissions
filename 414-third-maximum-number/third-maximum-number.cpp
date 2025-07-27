class Solution {
public:
 // build max heap 
    void maxhipify(vector<int>&nums,int n ,int i){
    int left=2*i+1;
    int right=2*i+2;
    int maximum=i;
    if(left<n && nums[left]>nums[i]){
        maximum=left;
    }
    if(right<n && nums[right]>nums[maximum] ){
        maximum=right;
    }
    if(maximum!=i){
        swap(nums[i],nums[maximum]);
        maxhipify(nums,n,maximum);
    }
}
// extract root element each time ( root is maximum element in maxheap  )
    void deleteRoot(vector<int>&nums,set<int>&s,int &n){
        int lastElement=nums[n-1];
        s.insert(nums[0]);
        nums[0]=lastElement;
        n=n-1;
        maxhipify(nums,n,0);
    }

 int thirdMax(vector<int>& nums) {
        if(nums.size()==1){            // when array size is 1
         return nums[0];   
        }
        if(nums.size()==2){               // when array size is 2
            return max(nums[0],nums[1]);
        }
        int n=nums.size();

        for(int i=nums.size()/2;i>=0;i--){    // build max heap 
            maxhipify(nums,n,i);
        }
        set<int>s;
        for(int i=0;i<nums.size();i++){   // extract root( maximum element each time )
            deleteRoot(nums,s,n);
        }
        if(s.size()<3){         //  3rd largest element does not exist 
            return *--s.end();
        }else{                 // set s size >=3 3rd largest element exist
                int index=s.size()-3; // 3rd maximum index (index start with 0 )
                // using next() function
                auto it = next(s.begin(), index);   
                return   *it;
        }
    }
};