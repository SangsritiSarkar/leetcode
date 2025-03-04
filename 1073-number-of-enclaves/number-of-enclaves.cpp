class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &vis, vector<int> &row, vector<int> &col, int nr, int nc)
    {

        vis[r][c] = 1;
        grid[r][c]=0;
        for(int i=0;i<4;++i){
            int delrow=r+row[i];
            int delcol=c+col[i];
            if(delrow>=0 and delrow<nr and delcol>=0 and delcol<nc and !vis[delrow][delcol] and grid[delrow][delcol]==1) dfs(delrow,delcol,grid,vis,row, col, nr,nc);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt=0;
        int nr=grid.size();
        int nc=grid[0].size();
        vector<vector<int>> vis(nr, vector<int> (nc));
        vector<int>  row={-1,0,1,0}, col={0,-1,0,1};
        for(int i=0;i<nr;++i) //boundary col
        {
           if(!vis[i][0] and grid[i][0]==1) dfs(i,0,grid,vis, row, col, nr, nc); //1st col
           if(!vis[i][nc-1] and grid[i][nc-1]==1) dfs(i,nc-1,grid,vis, row, col, nr, nc); //last col
        }
         for(int i=0;i<nc;++i) //boundary row
        {
           if(!vis[0][i] and grid[0][i]==1) dfs(0,i,grid,vis, row, col, nr, nc); //1st row
           if(!vis[nr-1][i] and grid[nr-1][i]==1) dfs(nr-1,i,grid,vis, row, col, nr, nc); //last row
        }   

        for(int i=0;i<nr;++i){
            for(int j=0;j<nc;++j){
                if(grid[i][j]==1) cnt++;
            }
        } 
        return cnt;  
    }
};