class Solution {
public:
    bool validPath(int n, vector<vector<int>>& ed, int src, int dst) {
       
        queue<int> q;
        vector<int> vis(n);
        unordered_map<int,vector<int>> adj;
        for(auto e:ed)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        q.push(src);
        vis[src]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(node==dst) return true;
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return false;
    }
};