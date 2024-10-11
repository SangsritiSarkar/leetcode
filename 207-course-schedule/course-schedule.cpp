class Solution {
private: 

    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)==true) return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }

        pathVis[node]=0;
        return false;

    }

public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==1) return true;
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[v].push_back(u);
            
        }

        int vis[numCourses];
        int pathVis[numCourses];

        for(int i=0;i<numCourses;i++){
            vis[i] = 0;
            pathVis[i]=0;
        }  
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)==true) return false;
            }
        }
        return true;

   }

};