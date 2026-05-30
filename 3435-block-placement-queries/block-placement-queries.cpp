class Solution {
public:
    struct SegTree {
        int n;
        vector<int> tree;

        SegTree(int n) {
            this->n = n;
            tree.assign(4 * n, 0);
        }

        void update(int node, int l, int r, int idx, int val) {
            if (l == r) {
                tree[node] = val;
                return;
            }

            int mid = (l + r) / 2;

            if (idx <= mid) {
                update(node * 2, l, mid, idx, val);
            } else {
                update(node * 2 + 1, mid + 1, r, idx, val);
            }

            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }

        int query(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql) return 0;
            if (ql <= l && r <= qr) return tree[node];

            int mid = (l + r) / 2;

            return max(
                query(node * 2, l, mid, ql, qr),
                query(node * 2 + 1, mid + 1, r, ql, qr)
            );
        }

        void update(int idx, int val) {
            update(1, 0, n - 1, idx, val);
        }

        int query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        int MAXX = 50005;

        set<int> obstacles;
        obstacles.insert(0);

        SegTree seg(MAXX);

        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                auto it = obstacles.upper_bound(x);

                int pre = *std::prev(it);

                if (it != obstacles.end()) {
                    int nxt = *it;
                    seg.update(nxt, nxt - x);
                }

                obstacles.insert(x);
                seg.update(x, x - pre);
            } 
            else {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);
                int last = *std::prev(it);

                int best = max(seg.query(0, x), x - last);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};