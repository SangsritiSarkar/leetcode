class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        int n=prereq.size();
        vector<int> adj[numCourses];
        for(int i=0;i<n;++i){
            int u=prereq[i][0];
            int v=prereq[i][1];

            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;++i) {
            for(auto it:adj[i]) indegree[it]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;++i) if(indegree[i]==0) q.push(i);
        int cnt=0;

        while(!q.empty()){
            int node=q.front();
            q.pop(); cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(cnt==numCourses) return true;
        return false;
    }
};