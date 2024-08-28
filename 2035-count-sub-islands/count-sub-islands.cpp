class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n,int m,int i, int j){
        if(i<0 or i>=n or j<0 or j>=m or grid2[i][j]!=1 ) return true;
        grid2[i][j]=-1;
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,-1,0,1};

        bool res=(grid1[i][j]==1);
        for(int k=0;k<4;k++){
            int x=i+dx[k], y=j+dy[k];
            res=res & dfs(grid1,grid2, n,m,x,y);
        }
        return res;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size(); //rows
        int m=grid2[0].size(); //col
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 and dfs(grid1,grid2,n,m,i,j)) ans++;
            }
        }
        return ans;
    }
};