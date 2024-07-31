class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele,cnt=0;
        for(int i=0;i<n;++i)
        {
            if(cnt==0){cnt=1; ele=nums[i];}
            else if(nums[i]==ele) cnt++;
            else cnt--;
        }
        int c=0;
        for(auto it:nums) if(it==ele) c++;
        if(c>n/2) return ele;
        return -1;
    }
};