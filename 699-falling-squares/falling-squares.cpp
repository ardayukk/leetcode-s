
class Solution {
public:
    struct SegmentTree {
        int n;
        vector<int> arr;
        vector<int> lazy;

        SegmentTree(int n) : n(n) {
            arr.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void apply(int node, int height) {
            arr[node] = height;
            lazy[node] = height;
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r)
                return;

            apply(node * 2, lazy[node]);
            apply(node * 2 + 1, lazy[node]);

            lazy[node] = 0;
        }

        void rangeAssign(int node, int l, int r,
                         int ql, int qr, int height) {
            if (qr < l || r < ql)
                return;

            if (ql <= l && r <= qr) {
                apply(node, height);
                return;
            }

            push(node, l, r);

            int mid = (l + r) / 2;

            rangeAssign(node * 2, l, mid, ql, qr, height);
            rangeAssign(node * 2 + 1, mid + 1, r, ql, qr, height);

            arr[node] = max(arr[node * 2], arr[node * 2 + 1]);
        }

        void rangeAssign(int l, int r, int height) {
            rangeAssign(1, 0, n - 1, l, r, height);
        }

        int rangeMax(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql)
                return 0;

            if (ql <= l && r <= qr)
                return arr[node];

            push(node, l, r);

            int mid = (l + r) / 2;

            return max(
                rangeMax(node * 2, l, mid, ql, qr),
                rangeMax(node * 2 + 1, mid + 1, r, ql, qr)
            );
        }

        int rangeMax(int l, int r) {
            return rangeMax(1, 0, n - 1, l, r);
        }
    };

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> coords;

        for (auto& v : positions) {
            coords.push_back(v[0]);
            coords.push_back(v[0] + v[1]);
        }

        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        SegmentTree st((int)coords.size() - 1);

        vector<int> ans;
        int highest = 0;

        for (auto& v : positions) {
            int left = v[0];
            int side = v[1];

            int L = lower_bound(coords.begin(), coords.end(), left)
                    - coords.begin();

            int R = lower_bound(coords.begin(), coords.end(), left + side)
                    - coords.begin() - 1;

            int base = st.rangeMax(L, R);
            int height = base + side;

            st.rangeAssign(L, R, height);

            highest = max(highest, height);
            ans.push_back(highest);
        }

        return ans;
    }
};
