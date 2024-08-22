class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-2;
        while(l<=h){
            int mid=(l+h)>>1;
            if(nums[mid]==nums[mid^1]) //left half
               l=mid+1; //move right
            else h=mid-1;
        }
        return nums[l];
    }
};