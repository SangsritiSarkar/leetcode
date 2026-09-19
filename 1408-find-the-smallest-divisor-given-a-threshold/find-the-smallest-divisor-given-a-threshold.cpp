class Solution {
public:
    bool possible(vector<int> &nums, int k, int threshold)
    {
        int cnt=0;
        for(auto it:nums){
            if(cnt>threshold) return false;
            cnt+=ceil(double(it)/k);
        }
        if(cnt>threshold) return false;
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=INT_MIN, mid;
        for(auto it:nums) high=max(it,high);
        while(low<=high){
            mid=low+(high-low)/2;
            if(possible(nums, mid, threshold)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};