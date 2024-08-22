class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //if in left half:  {1st occurence->even index 2nd occurence->odd index}//search in right
        //if in right half: {1st occurence->odd index  2nd occurence->even index} //search in left
        int n=nums.size();
        if(n==1) return nums[0];
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if((mid==0 and nums[mid]!=nums[mid+1]) or (mid==n-1 and nums[mid]!=nums[mid-1])) return nums[mid];
            if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid&1) //odd index
            {
                if(nums[mid]==nums[mid+1])//1st occurence
                    h=mid-1;
                else if(nums[mid]==nums[mid-1])//2nd occurence
                    l=mid+1;
            }
            else//even index
            {
                if(nums[mid]==nums[mid+1])//1st occurence
                    l=mid+1;
                else if(nums[mid]==nums[mid-1])//2nd occurence
                    h=mid-1;
            }

        }
        return -1;
    }
};