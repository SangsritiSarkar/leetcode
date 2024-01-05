class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(), maxi=1,c=0;
        vector<int> dp(n,1), ct(n,1);
        for(int i=0;i<n;i++)
        {
            for(int prev=0; prev<i;prev++)
            {
                if(nums[prev]<nums[i] && 1 + dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                    ct[i]=ct[prev];
                }
                else if(nums[prev]<nums[i] && 1+dp[prev]==dp[i])
                {
                    ct[i]+=ct[prev];
                }
            }
            if(dp[i]>maxi)
               maxi=dp[i];
        }
        //cout<<maxi<<endl;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi) c+=ct[i];
        }
        return c;
    }
};