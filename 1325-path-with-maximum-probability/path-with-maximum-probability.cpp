class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();++i) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> prob(n,0.0);
        prob[start]=1.0;

        priority_queue<int> q;
        q.push(start);

        while(!q.empty()){
            int curr=q.top();
            q.pop();

            for(auto x:adj[curr]){
                int node=x.first;
                double currprob=x.second;
                double newprob=prob[curr]*currprob;

                if(newprob>prob[node]){
                    prob[node]=newprob;
                    q.push(node);
                }
            }
        }
        return prob[end];
    }
};