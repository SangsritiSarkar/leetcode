class Solution {
public:
//TABULATION
  
    int maxProfit(vector<int>& val) {
        int n=val.size();
        vector<vector<int>> dp(n+1, vector<int>(5,0));
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans=3;trans>=0;trans--)
            {
                if(trans%2==0)
                {
                    profit=max(-val[ind]+dp[ind+1][trans+1], 0+dp[ind+1][trans]);
                }
                else
                {
                    profit=max(val[ind]+dp[ind+1][trans+1], 0+dp[ind+1][trans]);
                }
                dp[ind][trans]=profit;

            }
        }
        return dp[0][0];
    }
};