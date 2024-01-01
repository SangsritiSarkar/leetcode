class Solution {
public:
    
    bool isMatch(string s2, string s1) {
        int n=s1.size();
        int m=s2.size();
        vector<bool> prev(m+1,false), curr(m+1,false);
        prev[0]=true;;
        //for(int j=1;j<=m;j++) dp[0][j]=false;
        for(int i=1;i<=n;i++)
        {
            int flag=true;
            for(int ii=1;ii<=i;ii++)
            {
                if(s1[ii-1]!='*') {flag=false; break;}
            }
            curr[0]=flag;
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1] || s1[i-1]=='?')
                   curr[j]=prev[j-1];
                else if(s1[i-1]=='*')
                      curr[j]=prev[j] ||curr[j-1];
                else
                      curr[j]=false;  
            }
            prev=curr;
        }
        return prev[m];
    }
    
    
    
};