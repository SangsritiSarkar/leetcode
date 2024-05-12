class Solution {
public:
    void dfs(int r,int c, vector<vector<int>>& grid, vector<vector<int>>& vis, int nr, int nc)
    {
        vis[r][c]=1;
        grid[r][c]=0;
        int row[]={-1,0,1,0};
        int col[]={0,-1,0,1};
        for(int i=0;i<4;++i)
        {
            int delrow=r+row[i];
            int delcol=c+col[i];
            if(delrow >=0 and delrow <nr and delcol>=0 and delcol<nc and grid[delrow][delcol]==1 and !vis[delrow][delcol])
            {
                dfs(delrow,delcol,grid,vis,nr,nc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int nr=grid.size();
        int nc=grid[0].size();
        int s=0;
        vector<vector<int>> vis(nr,vector<int> (nc,0));
        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                if((i==0 or i==nr-1 or j==0 or j==nc-1) and grid[i][j]==1 and !vis[i][j])
                {
                   dfs(i,j,grid,vis,nr,nc);
                }
            }
        }
        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                s+=grid[i][j];
            }
        }
        return s;
    }
};