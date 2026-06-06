class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i<n; i++) {
            if (visited[i]) { continue; }

            components++;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int front = q.front();
                q.pop();
                for (auto v: adj[front]) {
                    if (visited[v]) { continue; }
                    
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        return components;
    }
};
