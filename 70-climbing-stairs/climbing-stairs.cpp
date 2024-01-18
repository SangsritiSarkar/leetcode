class Solution {
public:
    int f(int ind)
    {
        
        int dp[ind+1];
        if(ind<=2) return ind;
        else
        {
            dp[0]=0;
            dp[1]=1; 
            dp[2]=2;
            for(int i=3;i<=ind;i++)
            {
                dp[i]=dp[i-1]+dp[i-2];

            }
        }
        
        return dp[ind];
 
    }
    int climbStairs(int n) {
        return f(n);

    }
};