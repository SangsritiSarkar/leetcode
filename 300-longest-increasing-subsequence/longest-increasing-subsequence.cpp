class Solution {
public:
//TABULATION
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=ind-1;prev>=-1;prev--)
            {
                int notTake=0+dp[ind+1][prev+1];
                int take=0;
                if(prev==-1 || nums[ind]>nums[prev])
                   take=1+dp[ind+1][ind+1]; //COORDINATE SHIFT PREV part
                dp[ind][prev+1]=max(take, notTake);
            }
            
        }
        return dp[0][0];
       
    }
};