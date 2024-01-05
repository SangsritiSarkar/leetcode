class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(),maxi=1,lastInd;
        if(n==1) return nums;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1), hash(n);
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastInd=i;
            }
        }
         vector<int> lis;
        // lis[maxi-1]=nums[lastInd];
        // int ind=maxi-2;
        // while(lastInd!=hash[lastInd])
        // {
        //     lastInd=hash[lastInd];
        //     lis[ind--]=nums[lastInd];
        // }
        lis.push_back(nums[lastInd]);
        while(lastInd!=hash[lastInd])
        {
            lastInd=hash[lastInd];
            lis.push_back(nums[lastInd]);
        }
        reverse(lis.begin(),lis.end());
        return lis;
    }
};