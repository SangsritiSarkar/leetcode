class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for(int tar=0;tar<=amount;tar++)
        {
            dp[0][tar]=(tar%coins[0]==0);
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int tar=0;tar<=amount;tar++)
            {
                int notTake=dp[ind-1][tar];
                int take=0;
                if(coins[ind]<=tar) take=dp[ind][tar-coins[ind]];//not 1+..becoz it is no of ways
                dp[ind][tar]=take+notTake;
            }
        }
        return dp[n-1][amount];
        
    }
};