class Solution {
public:
    int timer=1;
    void dfs(int node, int parent, int tin[], int low[],  vector<int> adj[], vector<int> &vis,vector<vector<int>> &bridges )
    {
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it==parent) continue;
            else if(!vis[it])
            {
                dfs(it,node,tin,low,adj,vis,bridges);
                low[node]=min(low[node], low[it]);
                //node--it
                //if(low[it]<=tin[node])  then okay
                if(low[it]>tin[node])
                {
                    bridges.push_back({node,it});
                }
            }
            else
            {
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n);
        int tin[n], low[n];
        vector<vector<int>> bridges;
        dfs(0,-1,tin,low,adj,vis,bridges);
        return bridges;
    }
};