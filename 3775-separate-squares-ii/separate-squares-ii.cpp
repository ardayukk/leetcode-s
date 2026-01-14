class Solution {
public:
    struct Event {
        double y, x1, x2;
        int type;
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    struct SegTree {
        int n;
        vector<int> cover;
        vector<double> len;
        vector<double>& xs;

        SegTree(vector<double>& xs) : xs(xs) {
            n = xs.size() - 1;
            cover.assign(4 * n, 0);
            len.assign(4 * n, 0);
        }

        void pull(int v, int l, int r) {
            if (cover[v] > 0)
                len[v] = xs[r + 1] - xs[l];
            else if (l == r)
                len[v] = 0;
            else
                len[v] = len[v * 2] + len[v * 2 + 1];
        }

        void update(int v, int l, int r, int ql, int qr, int val) {
            if (qr < l || r < ql) return;
            if (ql <= l && r <= qr) {
                cover[v] += val;
                pull(v, l, r);
                return;
            }
            int m = (l + r) / 2;
            update(v * 2, l, m, ql, qr, val);
            update(v * 2 + 1, m + 1, r, ql, qr, val);
            pull(v, l, r);
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<double> xs;

        for (auto& s : squares) {
            double x1 = s[0];
            double x2 = s[0] + s[2];
            double y1 = s[1];
            double y2 = s[1] + s[2];

            events.push_back({y1, x1, x2, +1});
            events.push_back({y2, x1, x2, -1});

            xs.push_back(x1);
            xs.push_back(x2);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(events.begin(), events.end());

        SegTree st(xs);

        double totalArea = 0;
        double prevY = events[0].y;

        // First pass: compute total area
        for (int i = 0; i < events.size(); i++) {
            double y = events[i].y;
            totalArea += st.len[1] * (y - prevY);

            int l = lower_bound(xs.begin(), xs.end(), events[i].x1) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), events[i].x2) - xs.begin() - 1;
            st.update(1, 0, st.n - 1, l, r, events[i].type);

            prevY = y;
        }

        double half = totalArea / 2.0;

        // Reset for second sweep
        fill(st.cover.begin(), st.cover.end(), 0);
        fill(st.len.begin(), st.len.end(), 0);

        double curArea = 0;
        prevY = events[0].y;

        // Second pass: find exact Y
        for (int i = 0; i < events.size(); i++) {
            double y = events[i].y;
            double slice = st.len[1] * (y - prevY);

            if (curArea + slice >= half) {
                double remaining = half - curArea;
                return prevY + remaining / st.len[1];
            }

            curArea += slice;

            int l = lower_bound(xs.begin(), xs.end(), events[i].x1) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), events[i].x2) - xs.begin() - 1;
            st.update(1, 0, st.n - 1, l, r, events[i].type);

            prevY = y;
        }

        return prevY;
    }
};
