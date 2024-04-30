class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int n=mat.size();
      int m=mat[0].size();
      queue<pair<pair<int,int>,int>> q;
      vector<vector<int>> vis(n,vector<int> (m,0));
      vector<vector<int>> dist(n,vector<int> (m,0));
      int l=0;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                q.push({{i,j},l});
                vis[i][j]=1;
                //dist[i][j]=0;
            }
        }
      }
       int row[]={-1,0,1,0};
        int col[]={0,-1,0,1};
      while(!q.empty())
      {
        auto it=q.front();
        q.pop();
        int r=it.first.first;
        int c=it.first.second;
        int l=it.second;
        //dist[r][c]=l;
       
        
        for(int i=0;i<4;i++)
        {
            
                int delrow=r+row[i];
                int delcol=c+col[i];
                if(delrow>=0 and delrow<n and delcol>=0 and delcol<m and !vis[delrow][delcol])
                {
                   q.push({{delrow,delcol},l+1});
                   vis[delrow][delcol]=1;
                   dist[delrow][delcol]=l+1;
                }

            
        }
      }
      return dist;
    }
};