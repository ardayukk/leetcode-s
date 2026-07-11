class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int start = 0; start < n; start++) {
            if (visited[start]) continue;

            queue<int> q;
            vector<int> component;

            q.push(start);
            visited[start] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                component.push_back(u);

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            bool complete = true;

            for (int u : component) {
                if (adj[u].size() != component.size() - 1) {
                    complete = false;
                    break;
                }
            }

            if (complete) ans++;
        }

        return ans;
    }
};