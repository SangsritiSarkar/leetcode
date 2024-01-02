class Solution {
public:
//TABULATION
    
    int maxProfit(vector<int>& val) {
        int n=val.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0; buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    if(buy)
                    {
                        profit=max(-val[ind]+dp[ind+1][0][cap], 0+dp[ind+1][1][cap]);
                    }
                    else
                    {
                        profit=max(val[ind]+dp[ind+1][1][cap-1], 0+dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};