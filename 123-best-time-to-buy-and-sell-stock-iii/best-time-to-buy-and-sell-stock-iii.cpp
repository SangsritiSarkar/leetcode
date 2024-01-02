class Solution {
public:
//MEMOIZATION
    int f(int ind, int buy, int cap, int n ,vector<int> &val, vector<vector<vector<int>>>& dp)
    {
        if(cap==0 || ind==n) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit=0;
        if(buy)
        {
            profit=max(-val[ind]+f(ind+1,0,cap,n,val,dp), 0+f(ind+1,1,cap,n,val,dp));
        }
        else
        {
            profit=max(val[ind]+f(ind+1,1,cap-1,n,val,dp), 0+f(ind+1,0,cap,n,val,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,-1)));
        return f(0,1,2,n,prices,dp);
    }
};