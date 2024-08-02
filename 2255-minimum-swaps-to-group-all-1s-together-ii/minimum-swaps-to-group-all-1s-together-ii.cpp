class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(2*n);
        for(int i=0;i<2*n;++i) temp[i]=nums[i%n];
        int c1=accumulate(nums.begin(),nums.end(),0);
        int curr1=0;
        int i=0,j=0,maxi=0;
        while(j<2*n)
        {
            if(temp[j]==1) curr1++;
            if(j-i+1>c1) {
                curr1-=temp[i]; ++i;
            }
            maxi=max(maxi,curr1);
            ++j;
        }
        return c1-maxi;
    }
};