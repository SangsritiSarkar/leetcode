class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n);
        int cnt=0;
        for(auto i=0;i<n;++i){
            for(auto j=0;j<n;++j){
                if(i!=j and isConnected[i][j]) adj[i].push_back(j);
            }
        }
        
        for(int i=0;i<n;++i){
                if(!vis[i]){
                    dfs(i, vis, adj);
                    cnt++;
                }
            
        }
        return cnt;
    }
};