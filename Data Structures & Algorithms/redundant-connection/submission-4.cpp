class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        for (auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> deg(adj.size(), 0);
        queue<int> q;
        for (int i = 1; i<adj.size(); i++) {
            deg[i] = adj[i].size();
            if (deg[i] == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int front = q.front();
            deg[front]--;
            q.pop();
            for (auto v: adj[front]) {
                deg[v]--;
                if (deg[v] == 1) {
                    q.push(v);
                }
            }
        }
        for (int i = edges.size()-1; i>=0; i--) {
            if (deg[edges[i][0]] == 2 && deg[edges[i][1]]) { return edges[i]; }
        }
        return {};
    }
};
