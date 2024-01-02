class Solution {
public:
    int maxProfit(vector<int>& val) {
        int n=val.size();
        vector<vector<int>> dp(n+2, vector<int> (2,0));
       
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            
            for(int buy=0;buy<=1;buy++)
            {
                dp[ind][1]=max(-val[ind]+dp[ind+1][0], dp[ind+1][1]);
                dp[ind][0]=max(val[ind]+dp[ind+2][1], dp[ind+1][0]);
            }
        }
        return dp[0][1];    
    }
};