class Solution {
public:
//MEMOIZATION
    int f(int ind, int trans, int n ,vector<int> &val, vector<vector<int>>& dp)
        {
            if(trans==4 || ind==n) return 0;
            if(dp[ind][trans]!=-1) return dp[ind][trans];
            int profit=0;
            if(trans%2==0)
            {
                profit=max(-val[ind]+f(ind+1,trans+1,n,val,dp), 0+f(ind+1,trans,n,val,dp));
            }
            else
            {
                profit=max(val[ind]+f(ind+1,trans+1,n,val,dp), 0+f(ind+1,trans,n,val,dp));
            }
            return dp[ind][trans]=profit;
        }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(4,-1));
        return f(0,0,n,prices,dp);
    }
};