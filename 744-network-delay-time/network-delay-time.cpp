class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            
        }

        vector<int> dist(n+1,1e9);

        //set
        set<pair<int,int>> st;

        st.insert({0,k});
        dist[k]=0;
        while(!st.empty()){
            auto x=*(st.begin());
            int node=x.second;
            int d=x.first;
            st.erase(x);
            for(auto it:adj[node]){
                int adjNode=it.first;
                int adjDist=it.second;
                if(d+adjDist<dist[adjNode]) {
                    if(dist[adjNode]!=1e9) st.erase({dist[adjNode], adjNode});
                    dist[adjNode]=d+adjDist;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(dist[i],ans);
            if(ans==1e9) return -1;
        }
        return ans;
        
    }
};