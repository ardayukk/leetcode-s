class Solution {
public:
    struct DSU {
        vector<int> p, r;
        DSU(int n) : p(n), r(n, 0) {
            iota(p.begin(), p.end(), 0);
        }
        int find(int x) {
            return p[x] == x ? x : p[x] = find(p[x]);
        }
        bool unite(int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return false;
            if (r[a] < r[b]) swap(a, b);
            p[b] = a;
            if (r[a] == r[b]) r[a]++;
            return true;
        }
    };

    bool can(int n, vector<vector<int>>& edges, int k, int x) {
        DSU dsu(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must) {
                if (s < x) return false;
                if (!dsu.unite(u, v)) return false;
            }
        }

        vector<pair<int, pair<int,int>>> cand;
        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must) continue;
            if (s >= x) cand.push_back({0, {u, v}});
            else if (2 * s >= x) cand.push_back({1, {u, v}});
        }

        sort(cand.begin(), cand.end());

        int used = 0, edgesUsed = 0;
        for (auto& c : cand) {
            int cost = c.first;
            int u = c.second.first, v = c.second.second;
            if (dsu.unite(u, v)) {
                used += cost;
                edgesUsed++;
                if (used > k) return false;
            }
        }

        int root = dsu.find(0);
        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root) return false;
        }
        return used <= k;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lo = 0, hi = 200000, ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(n, edges, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};