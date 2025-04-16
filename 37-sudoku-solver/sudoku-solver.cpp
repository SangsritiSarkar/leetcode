class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>> &board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1' ; c<='9';c++)
                    {
                        if(isValid(board,i,j,c))
                        {
                            board[i][j]=c;
                            if(solve(board) == true) return true;
                            board[i][j]='.';   
    
                        }
                    }
                    return false; //not able to place anyonr in empty location
                }
            }
        }
        return true;//no empty space left i.e never had empty space in the nested for loops
                    //                    i.e. never return true or false i.e base case
                    //                    i.e filled everything..no empty space
                    //Therefore return true
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c) // no other c in same row.. i.e row fixed
               return false;
            else if(board[i][col]==c) // no other c in same col.. i.e col fixed
               return false;
            else if(board[3*(row/3) + i/3][3*(col/3) + i%3]==c)
               return false; 


        }
        return true;

    }
};