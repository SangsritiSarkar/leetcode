class Solution {
public:
//RECURSION
    // int f(int ind, int buy, vector<int>& val, int n)
    // {
    //     if(ind==n) return 0;
    //     int profit=0;
    //     if(buy)
    //     {
    //         profit=max(-val[ind]+f(ind+1,0,val,n), 0+f(ind+1,1,val,n));
    //     }
    //     else
    //     {
    //         profit=max(val[ind]+f(ind+1,1,val,n), 0+f(ind+1,0,val,n));
    //     }
    //     return profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     return f(0,1,prices,n);
    // }

//MEMOIZATION
    int f(int ind, int buy, vector<int>& val, int n,vector<vector<int>>& dp)
    {
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy)
        {
            profit=max(-val[ind]+f(ind+1,0,val,n,dp), 0+f(ind+1,1,val,n,dp));
        }
        else
        {
            profit=max(val[ind]+f(ind+1,1,val,n,dp), 0+f(ind+1,0,val,n,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2,-1));
        return f(0,1,prices,n,dp);
    }
};