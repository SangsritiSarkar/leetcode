class Solution {
public:

    bool possible(int node, int flower, vector<int> &c, vector<vector<int>> &adj){
        for(auto it:adj[node]){
            if(c[it-1]==flower) return false;
        }
        return true;
    }

    bool solve(int node, int n, vector<int> &c, vector<vector<int>> &adj){
        if(node==n+1){
            return true;
        }
        for(int flower=1; flower<=4; ++flower){
            if(possible(node, flower,c, adj)){
                c[node-1]=flower;
                if(solve(node+1,n,c,adj)) return true;
                c[node-1]=0;
            }
        }
        return false;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        vector<int> c(n,0);
        
        for(auto it: paths)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=1;i<=n;++i)
        {
            if(!c[i-1]){
                if(!solve(i,n,c,adj)) continue;
            }
        }
        return c;
    }
};