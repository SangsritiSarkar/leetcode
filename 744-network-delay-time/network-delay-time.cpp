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

        //min_heap
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq; 

        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int adjDist=it.second;
                if(d+adjDist<dist[adjNode]) {
                    dist[adjNode]=d+adjDist;
                    pq.push({dist[adjNode],adjNode});
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