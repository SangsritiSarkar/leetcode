class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>> &vis, vector<int> &row, vector<int> &col, int nr, int nc)
    {

        vis[r][c] = 1;
        for(int i=0;i<4;++i){
            int delrow=r+row[i];
            int delcol=c+col[i];
            if(delrow>=0 and delrow<nr and delcol>=0 and delcol<nc and !vis[delrow][delcol] and board[delrow][delcol]=='O') dfs(delrow,delcol,board,vis,row, col, nr,nc);
        }
    }
    void solve(vector<vector<char>>& board) {
        int nr= board.size();
        int nc= board[0].size();
        vector<vector<int>> vis(nr, vector<int> (nc));
        vector<int>  row={-1,0,1,0}, col={0,-1,0,1};
        for(int i=0;i<nr;++i) //boundary col
        {
           if(!vis[i][0] and board[i][0]=='O') dfs(i,0,board,vis, row, col, nr, nc); //1st col
           if(!vis[i][nc-1] and board[i][nc-1]=='O') dfs(i,nc-1,board,vis, row, col, nr, nc); //last col
        }
         for(int i=0;i<nc;++i) //boundary row
        {
           if(!vis[0][i] and board[0][i]=='O') dfs(0,i,board,vis, row, col, nr, nc); //1st row
           if(!vis[nr-1][i] and board[nr-1][i]=='O') dfs(nr-1,i,board,vis, row, col, nr, nc); //last row
        }

        for(int i=1; i<nr-1; ++i)
        {
            for(int j=1;j<nc-1;++j)
            {
                if(!vis[i][j] and board[i][j]=='O'){
                    vis[i][j]=1;
                    board[i][j]='X';
                }
            }
        }
    }
};