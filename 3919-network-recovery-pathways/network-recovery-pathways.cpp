class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<bool> online;
    int n;

    bool findPossible(long long k, int minEdge) {
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            if (d > k) return false;

            if (u == n - 1) return true;

            for (auto &[v, w] : adj[u]) {
                if (!online[v]) continue;
                if (w < minEdge) continue;

                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online_, long long k) {
        online = online_;
        n = online.size();
        adj.assign(n, {});

        int mx = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            mx = max(mx, w);
        }

        int l = 0;
        int r = mx;
        int ans = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (findPossible(k, m)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
};