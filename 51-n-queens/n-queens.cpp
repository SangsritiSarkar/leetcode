class Solution {
public:

    bool safe(int r, int col, vector<string> board, int n){
        //upper diagonal
        int dr=r, dc=col;
        while(dr>=0 and dc>=0){
            if(board[dr][dc]=='Q') return false;
            dr--; dc--;
        }
        //left
        dc=col;
        while(dc>=0){
            if(board[r][dc]=='Q') return false;
            dc--;
        }
        //lower diagonal
        dr=r, dc=col;
        while(dr<n and dc>=0){
            if(board[dr][dc]=='Q') return false;
            dr++; dc--;
        }
        return true;
    }


    void solve(vector<vector<string>> &ans, vector<string> &board, int col, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int r=0;r<n;++r){
            if(safe(r,col,board,n)){
                board[r][col]='Q';
                solve(ans, board, col+1,n);
                board[r][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');
        for(int i=0;i<n;++i) board[i]=s;
        solve(ans, board, 0,n);
        return ans;
    }
};