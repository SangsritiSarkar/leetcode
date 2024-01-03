class Solution {
public:
//MEMOIZATION
    // int f(int i, int j, vector<vector<int>>& matrix, int m, vector<vector<int>> &dp)
    // {
       
    //     if(j<0 || j>=m) return 200;
    //     if(i==0) return matrix[0][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int up=matrix[i][j]+f(i-1,j,matrix,m,dp);
    //     int ldg=matrix[i][j]+f(i-1,j-1,matrix,m,dp);
    //     int rdg=matrix[i][j]+f(i-1,j+1,matrix,m,dp);
 
    //     return dp[i][j]=min(up, min(ldg,rdg));
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     vector<vector<int>> dp(n,vector<int> (m,-1));
    //     int mini=INT_MAX;
    //     for(int j=0;j<m;j++)
    //     {
    //         int ans=f(n-1,j,matrix,m,dp);
    //         mini=min(mini,ans);
    //     }
    //     return mini;
    // }
 //TABULATION  
     int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        int mini=INT_MAX;
        //BASE CONDITION
        for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];
        for(int i=1;i<n;i++)
        {
           for(int j=m-1;j>=0;j--)
           {
               
               int up=matrix[i][j]+dp[i-1][j];
               int ldg=matrix[i][j];
               if(j-1>=0) ldg+=dp[i-1][j-1];
               else ldg+=1e9;
               int rdg=matrix[i][j];
               if(j+1<m) rdg+=dp[i-1][j+1];
               else rdg+=1e9;

               dp[i][j]=min(up,min(ldg,rdg));
           }
        }
        for(int j=0;j<m;j++) mini=min(mini,dp[n-1][j]);
        return mini;
    }

    //SPACE OPTIMZATION 
    //  int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     vector<int> prev(m,0);
    //     int mini=INT_MAX;
    //     //BASE CONDITION
    //     for(int j=0;j<m;j++) prev[j]=matrix[0][j];
    //     for(int i=1;i<n;i++)
    //     {
    //         vector<int> curr(n,0);
    //        for(int j=0;j<m;j++)
    //        {
               
    //            int up=matrix[i][j]+prev[j];
    //            int ldg=matrix[i][j];
    //            if(j-1>=0) ldg+=prev[j-1];
    //            else ldg+=1e9;
    //            int rdg=matrix[i][j];
    //            if(j+1<m) rdg+=prev[j+1];
    //            else rdg+=1e9;

    //            curr[j]=min(up,min(ldg,rdg));
    //        }
    //        prev=curr;
    //     }
    //     for(int j=0;j<m;j++) mini=min(mini,prev[j]);
    //     return mini;
    // }
};