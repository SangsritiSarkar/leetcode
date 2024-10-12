class Solution {
public:
    void toposort(int node, vector<int>& edges, vector<int>& vis, stack<int> &st) {
        vis[node]=1;
        int it= edges[node]; 
        if(it!=-1 and !vis[it]) toposort(it, edges,vis,st);
        
        st.push(node);
    }

    void dfs(int node, vector<vector<int>> &revadj, vector<int>& vis, int &cnt){
        vis[node]=1; cnt++;
        for(auto it:revadj[node]) {
            if(!vis[it]) dfs(it,revadj,vis,cnt);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        

        vector<int> vis(n);
        stack<int> st;
        //TOPOSORT DFS
        for(int i=0;i<n;++i){
            if(edges[i]!=-1 and !vis[i]) toposort(i,edges,vis,st);
        }

        //REVERSE GRAPH
        vector<vector<int>> revadj(n);
        for(int i=0;i<n;++i){
            vis[i]=0;
            if(edges[i]!=-1) revadj[edges[i]].push_back(i);
        }

        //DFS ON REVERSE GRAPH ACCORDING TO FINISH TIME I.E STACK
        int ans=0,cnt;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                cnt=0;
                dfs(node,revadj,vis,cnt);
                ans=max(ans,cnt);
            }
            
        }
        if(ans==1) return -1;
        return ans;
    }
};