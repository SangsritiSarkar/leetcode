class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int nr=mat.size();
        int nc=mat[0].size();
        int l=0;
        vector<vector<int>> vis(nr, vector<int> (nc));
        vector<vector<int>> dis(nr, vector<int> (nc));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<nr;++i){
            for(int j=0;j<nc;++j){
                if(mat[i][j]==0) {
                    q.push({{i,j},l});
                    vis[i][j]=1;
                }
            }
        }

        vector<int> row={-1,0,1,0};
        vector<int> col={0,-1,0,1};

        while(!q.empty()){
            auto node=q.front();
            int r=node.first.first;
            int c=node.first.second;
            int lev=node.second;
            dis[r][c]=lev;
            q.pop();

            for(auto i=0;i<4;i++)
            {
                int delrow=r+row[i];
                int delcol=c+col[i];

                if(delrow>=0 and delrow<nr and delcol>=0 and delcol<nc and !vis[delrow][delcol]){
                    q.push({{delrow,delcol},lev+1});
                    vis[delrow][delcol]=1;
                }
            }
        }
        return dis;
    }
};