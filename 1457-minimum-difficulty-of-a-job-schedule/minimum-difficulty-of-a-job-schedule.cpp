class Solution {
public:
    int f(int ind, int d, int n, vector<int>& jd, vector<vector<int>>& dp)
    {
        //BASE CASE
        //When only 1 day return max from that ind till the last
        if(d==1)
        {
            int maxi=jd[ind];
            for(int i=ind;i<n;i++) maxi=max(jd[i],maxi);
            return maxi;
        }
        if(dp[ind][d]!=-1) return dp[ind][d];
        int maxP=jd[ind];
        int ans=INT_MAX;
        for(int i=ind;i<=n-d;i++)
        {
            maxP=max(maxP,jd[i]);

            int res=maxP+f(i+1,d-1,n,jd,dp);
            ans=min(ans,res);
        }
        return dp[ind][d]=ans;
    }
    int minDifficulty(vector<int>& arr, int d) {
        int n=arr.size();
        if(d>n) return -1;
        vector<vector<int>> dp(n, vector<int> (d+1,-1));
        return f(0,d,n,arr,dp);
    }
};