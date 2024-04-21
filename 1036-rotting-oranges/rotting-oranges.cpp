class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nr=grid.size();
        int nc=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        int ans=0;
        while(!q.empty())
        {
            auto node=q.front();
            int row=node.first.first;
            int col=node.first.second;
            int time=node.second;
            q.pop();
            int r[]={0,1,0,-1};
            int c[]={-1,0,1,0};
            for(int i=0;i<4;i++)
            {
                int delrow=row+r[i];
                int delcol=col+c[i];
                if(delrow>=0 and delrow<nr and delcol>=0 and delcol<nc and grid[delrow][delcol]==1)
                {
                    q.push({{delrow,delcol},time+1});
                    grid[delrow][delcol]=2;
                    ans=max(ans,time+1);
                }
            }
        }
        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++) 
               if(grid[i][j]==1) return -1;
        }
        return ans;
    }
};