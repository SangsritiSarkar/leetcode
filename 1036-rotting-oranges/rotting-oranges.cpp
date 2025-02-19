class Solution {
public:
    void bfs(int tr, int tc, vector<vector<int>> &grid , queue<pair<pair<int,int>, int>> &q, int &ans){
        
        
        vector<int> delrow={-1,0,0,1};
        vector<int> delcol={0,-1,1,0};
        while(!q.empty()){
            auto node=q.front();
            int r=node.first.first;
            int c=node.first.second;
            int time=node.second;
            
            
            q.pop();
            for(int i=0;i<4;++i)
            {
                int newr=r+delrow[i], newc=c+delcol[i];
                if(newr>=0 and newr<tr and newc>=0 and newc<tc and grid[newr][newc]==1)            {
                    q.push({{newr,newc},time+1});
                    grid[newr][newc]=2;
                    ans=max(ans,time+1);
                }
            }
        }

        for(auto it: grid)
        {
            for(auto j:it) if(j==1) {ans=-1; break;}
        }

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int nr=grid.size(), nc=grid[0].size(), ans=0;
       
        queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<nr;++i)
        {
            for(int j=0;j<nc;++j)
            {
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    
                }
            }
        }
        bfs(nr,nc, grid, q, ans);
        return ans;
    }
};