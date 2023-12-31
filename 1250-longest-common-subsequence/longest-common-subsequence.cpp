class Solution {
public:
    //MEMOIZATION
    // int f(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp)
    // {
    //     if(ind1<0 || ind2<0) return 0;
    //     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    //     if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]=1+f(ind1-1, ind2-1, s1,s2,dp);
    //     return dp[ind1][ind2]=max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n=text1.size();
    //     int m=text2.size(); 
    //     vector<vector<int>> dp(n, vector<int> (m,-1));
    //     return f(n-1,m-1,text1,text2,dp);
    // }

    //MEMOIZATION SHIFT RIGHT INDEX
    // int f(int i, int j, string s1, string s2, vector<vector<int>>& dp)
    // {
    //     if(i==0 || j==0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i-1]==s2[j-1]) return dp[i][j]=1+f(i-1, j-1, s1,s2,dp);
    //     return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n=text1.size();
    //     int m=text2.size(); 
    //     vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
    //     return f(n,m,text1,text2,dp);
    // }

   //SPACE OPTIMIZATION
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size(); 
        vector<int> prev(m+1,0), curr(m+1,0);
        //for(int i=0;i<=n;i++) dp[i][0]=0; //column no neeed
        for(int j=0;j<=m;j++) prev[j]=0; 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
        
    }
    

    
};