#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct SegTree {
        int n; // we build on [0..n]
        vector<int> mn, mx, lazy;

        SegTree(int n_) : n(n_) {
            mn.assign(4 * (n + 1), 0);
            mx.assign(4 * (n + 1), 0);
            lazy.assign(4 * (n + 1), 0);
            build(1, 0, n);
        }

        void build(int u, int l, int r) {
            mn[u] = mx[u] = 0;
            lazy[u] = 0;
            if (l == r) return;
            int mid = (l + r) / 2;
            build(u * 2, l, mid);
            build(u * 2 + 1, mid + 1, r);
        }

        void apply(int u, int v) {
            mn[u] += v;
            mx[u] += v;
            lazy[u] += v;
        }

        void pushDown(int u) {
            if (lazy[u] != 0) {
                apply(u * 2, lazy[u]);
                apply(u * 2 + 1, lazy[u]);
                lazy[u] = 0;
            }
        }

        void pullUp(int u) {
            mn[u] = min(mn[u * 2], mn[u * 2 + 1]);
            mx[u] = max(mx[u * 2], mx[u * 2 + 1]);
        }

        // add v to all indices in [L..R]
        void addRange(int u, int l, int r, int L, int R, int v) {
            if (R < l || r < L) return;
            if (L <= l && r <= R) {
                apply(u, v);
                return;
            }
            pushDown(u);
            int mid = (l + r) / 2;
            addRange(u * 2, l, mid, L, R, v);
            addRange(u * 2 + 1, mid + 1, r, L, R, v);
            pullUp(u);
        }

        void addRange(int L, int R, int v) { // convenience
            if (L > R) return;
            addRange(1, 0, n, L, R, v);
        }

        // Find the smallest index pos such that pref[pos] == target.
        // We rely on: within any segment, pref hits every integer between mn and mx.
        int firstPosWithValue(int u, int l, int r, int target) {
            if (l == r) return l;
            pushDown(u);
            int mid = (l + r) / 2;
            int left = u * 2;
            int right = u * 2 + 1;

            // If target is within [mn,mx] of left child, it must exist there.
            if (mn[left] <= target && target <= mx[left]) {
                return firstPosWithValue(left, l, mid, target);
            }
            return firstPosWithValue(right, mid + 1, r, target);
        }

        int firstPosWithValue(int target) {
            return firstPosWithValue(1, 0, n, target);
        }
    };

    int longestBalanced(vector<int>& nums) {
        int n = (int)nums.size();
        SegTree st(n);                 // indices 0..n (prefix indices)
        unordered_map<int,int> last;   // last[value] = last position (1..n)
        last.reserve(n * 2);

        int now = 0; // current pref[r]
        int ans = 0;

        // r goes from 1..n (we treat prefix index 0 as "before array starts")
        for (int r = 1; r <= n; r++) {
            int x = nums[r - 1];
            int det = (x & 1) ? +1 : -1;

            // If x had an old last occurrence, remove its contribution from prefixes >= old
            if (last.find(x) != last.end()) {
                int old = last[x];
                st.addRange(old, n, -det);
                now -= det;
            }

            // Add x as last occurrence at r: prefixes >= r gain det
            last[x] = r;
            st.addRange(r, n, det);
            now += det;

            // Need smallest p such that pref[p] == pref[r] (= now)
            int p = st.firstPosWithValue(now);
            ans = max(ans, r - p); // subarray is [p+1 .. r]
        }

        return ans;
    }
};
