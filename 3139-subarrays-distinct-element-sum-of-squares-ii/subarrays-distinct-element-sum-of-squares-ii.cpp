#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    struct SegmentTree {
        int n;
        vector<long long> sum;
        vector<long long> sumSq;
        vector<long long> lazy;

        SegmentTree(int n) : n(n) {
            sum.assign(4 * n, 0);
            sumSq.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void apply(int node, int l, int r, long long add) {
            long long len = r - l + 1;

            sumSq[node] =
                (sumSq[node]
                + 2LL * add % MOD * sum[node] % MOD
                + add * add % MOD * len % MOD) % MOD;

            sum[node] =
                (sum[node]
                + add * len) % MOD;

            lazy[node] =
                (lazy[node] + add) % MOD;
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0) return;

            int mid = (l + r) / 2;

            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);

            lazy[node] = 0;
        }

        void rangeAdd(int node, int l, int r,
                      int ql, int qr, int val) {

            if (qr < l || r < ql)
                return;

            if (ql <= l && r <= qr) {
                apply(node, l, r, val);
                return;
            }

            push(node, l, r);

            int mid = (l + r) / 2;

            rangeAdd(node * 2, l, mid, ql, qr, val);
            rangeAdd(node * 2 + 1, mid + 1, r, ql, qr, val);

            sum[node] =
                (sum[node * 2] + sum[node * 2 + 1]) % MOD;

            sumSq[node] =
                (sumSq[node * 2] + sumSq[node * 2 + 1]) % MOD;
        }

        void rangeAdd(int l, int r, int val) {
            if (l > r) return;
            rangeAdd(1, 0, n - 1, l, r, val);
        }

        long long totalSquares() {
            return sumSq[1];
        }
    };

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        SegmentTree st(n);

        unordered_map<int,int> last;

        long long ans = 0;

        for (int r = 0; r < n; r++) {

            int p = -1;

            if (last.count(nums[r]))
                p = last[nums[r]];

            st.rangeAdd(p + 1, r, 1);

            ans = (ans + st.totalSquares()) % MOD;

            last[nums[r]] = r;
        }

        return (int)ans;
    }
};