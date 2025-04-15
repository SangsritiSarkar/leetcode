class Solution {
public:

    bool isSafe(int row, int col, vector<string> &board, int n){
        int dupr=row, dupc=col;
        //upper diagonal
        while(row>=0 & col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=dupr;col=dupc;
        //lower diagonal
        while(row<n and col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        row=dupr;col=dupc;
        //left
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        return true;
    }

    void solve(int col,vector<string> &board, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
            for(int r=0;r<n;++r){
                if(isSafe(r,col,board,n)){
                    board[r][col]='Q';
                    solve(col+1,board,ans,n);
                    board[r][col]='.';
                }
            }
        
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        vector<vector<string>> ans;
        for(int i=0;i<n;++i) board[i]=s;
        solve(0,board,ans,n);
        return ans;
    }
};