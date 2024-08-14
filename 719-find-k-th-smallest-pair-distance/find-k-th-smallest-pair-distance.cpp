class Solution {
public:
    bool check(int mid, vector<int> &nums, int k){
        int tot=0;
        int j=0,n=nums.size();
        for(int i=0;i<n;++i){
            while(j<n and nums[j]-nums[i]<=mid) ++j;
            --j;
            tot+=(j-i);
        }
        return tot>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums[n-1]-nums[0];
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid, nums,k)) r=mid;
            else l=mid+1;
        }
        return l;

    }
};