class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       
        int n=nums.size(), maxi=1;
        vector<int> dp(n,1), hash(n,1);
        for(int i=0;i<n;i++)
        {
            for(int prev=0; prev<i;prev++)
            {
                if(nums[prev]<nums[i])
                {
                    dp[i]=max(dp[i], 1+dp[prev]);
                }
            }
            if(dp[i]>maxi)
               maxi=dp[i];
        }
        return maxi;
    }
};