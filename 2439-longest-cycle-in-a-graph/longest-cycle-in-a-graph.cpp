class Solution {
public:
    vector<bool> visited;
    int count;

    int longestCycle(vector<int>& edges) {
        int len = edges.size();
        stack<int> st;
        visited.resize(len, false);

        // Run random order DFS and add vertices to stack while backtracking
        for (int i = 0; i < len; i++) {
            if (edges[i] != -1 && !visited[i])
                dfs(edges, i, st);
        }

        // Construct a graph with reversed edges
        vector<vector<int>> graph(len);
        for (int i = 0; i < len; i++) {
            if (edges[i] != -1)
                graph[edges[i]].push_back(i);
        }

        // Reset the visited array
        fill(visited.begin(), visited.end(), false);

        int maxCycle = 0;

        // Run stack-wise DFS to mark Strongly Connected Components
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            if (visited[top])
                continue;
            count = 0;
            specialDfs(graph, top);
            maxCycle = max(maxCycle, count);
        }

        return maxCycle > 1 ? maxCycle : -1;
    }

    void dfs(vector<int>& edges, int source, stack<int>& st) {
        visited[source] = true;
        int child = edges[source];
        if (child != -1 && !visited[child])
            dfs(edges, child, st);
        st.push(source); 
    }

    void specialDfs(vector<vector<int>>& graph, int source) {
        visited[source] = true;
        // Count the number of elements in each Strongly Connected Component
        count++;
        for (int child : graph[source]) {
            if (!visited[child]) 
                specialDfs(graph, child);
        }
    }
};
