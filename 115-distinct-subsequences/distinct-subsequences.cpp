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

//SPACE OPTIMIZATION   
    
    int numDistinct(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<double> prev(m+1,0), curr(m+1,0);
        prev[0]=curr[0]=1;
        //for(int j=1;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    curr[j]= prev[j-1]+prev[j];
            else
                curr[j]=prev[j]; 
            }
            prev=curr;
        }
        
        return (int)prev[m];

    }  
    
};