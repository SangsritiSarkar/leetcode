class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(d>n) return -1;
        vector<vector<int>> dp(n, vector<int> (d+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][1]=*max_element(begin(jd)+i, end(jd));
        }
        for(int day=2;day<=d;day++)
        {
            for(int i=0;i<=n-day;i++)
            {
                int maxP=INT_MIN;
                int ans=INT_MAX;
                for(int j=i;j<=n-day;j++)
                {
                    maxP=max(maxP,jd[j]);

                    int res=maxP+dp[j+1][day-1];
                    ans=min(ans,res);
                }
                dp[i][day]=ans;

            }
        }
        return dp[0][d];
    }
};