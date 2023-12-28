class Solution {
public:
    //MEMOIZATION
    // int f(int ind,int target, vector<int>& coins, vector<vector<int>>& dp)
    // {
    //     if(ind==0)
    //     {
    //         if(target%coins[0]==0) return target/coins[0];
    //         return 1e9;
    //     }
    //     if(dp[ind][target]!=-1) return dp[ind][target];
    //     int notTake=0+f(ind-1,target,coins,dp);
    //     int take=INT_MAX;
    //     if(coins[ind]<=target) take=1+f(ind,target-coins[ind],coins,dp);
    //     return dp[ind][target]=min(take, notTake);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n=coins.size();
    //     vector<vector<int>> dp(n, vector<int> (amount+1, -1));
    //     int ans= f(n-1,amount,coins,dp);
    //     if(ans>=1e9) return -1;
    //     return ans;
    // }

    //TABULATION
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        //BASE CASE
        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0) dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }
        //STATES
        for(int ind=1;ind < n;ind++)
        {
            for(int target=0;target <= amount;target++)
            {
                int notTake=0+dp[ind-1][target];
                int take=1e9;
                if(coins[ind]<=target) take=1+dp[ind][target-coins[ind]];
                dp[ind][target]=min(take, notTake);
            }
        }
        if(dp[n-1][amount]>=1e9) return -1;
        return dp[n-1][amount];
        
    }
};