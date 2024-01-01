class Solution {
public:
//NORMAL MEMOIZATION
    // int f(int i,int j, string s1, string s2,vector<vector<int>>& dp)
    // {
    //     if(j<0) return 1;
    //     if(i<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i]==s2[j]){
    //         return dp[i][j]= f(i-1,j-1,s1,s2,dp)+f(i-1,j,s1,s2,dp);
    //     }
    //     else
    //       return dp[i][j]=f(i-1,j,s1,s2,dp); 
    // }
    // int numDistinct(string s1, string s2) {
    //     int n=s1.size();
    //     int m=s2.size();
    //     vector<vector<int>> dp(n, vector<int> (m,-1));
    //     //for

    //     return f(n-1,m-1,s1,s2,dp);

    // }
//1 INDEX BASED MEMOIZATION   
    // int f(int i,int j, string s1, string s2,vector<vector<int>>& dp)
    // {
    //     if(j==0) return 1;
    //     if(i==0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i-1]==s2[j-1]){
    //         return dp[i][j]= f(i-1,j-1,s1,s2,dp)+f(i-1,j,s1,s2,dp);
    //     }
    //     else
    //       return dp[i][j]=f(i-1,j,s1,s2,dp); 
    // }
    // int numDistinct(string s1, string s2) {
    //     int n=s1.size();
    //     int m=s2.size();
    //     vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
    //     //for

    //     return f(n,m,s1,s2,dp);

    // } 

//TABULATION   
    
    /*int numDistinct(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<double>> dp(n+1, vector<double> (m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        //for(int j=1;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1]){
                    int count =dp[i-1][j-1];
                    int stay= dp[i-1][j];
                    dp[i][j]= count+stay;
                }
            else
                dp[i][j]=dp[i-1][j]; 
            }
        }
        
        return (int)dp[n][m];

    }  */
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        for(int i=0;i<=m;i++)
            dp[i][0] = 1;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[m][n];
    }
};