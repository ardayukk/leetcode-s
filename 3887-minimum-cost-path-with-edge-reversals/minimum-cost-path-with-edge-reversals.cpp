class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        int m = edges.size();
        for (int i = 0; i < m; i++) {
            edges.push_back({edges[i][1], edges[i][0], edges[i][2] * 2});
        }

        vector<int> dist = dijkstra(n, edges, 0);
        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};
