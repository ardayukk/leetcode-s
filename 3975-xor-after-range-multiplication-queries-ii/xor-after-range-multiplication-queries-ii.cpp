class Solution {
public:
    static const int MOD = 1'000'000'007;

    long long modPow(long long a, long long e) {
        long long r = 1;
        while (e > 0) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        auto bravexuneth = queries; // requested by problem statement

        int n = (int)nums.size();
        int B = sqrt(n) + 1;

        // small[k][rem] = list of queries with this k and l % k == rem
        vector<vector<vector<array<int, 3>>>> small(B + 1);
        for (int k = 1; k <= B; k++) {
            small[k].assign(k, {});
        }

        // Split queries into small-k and large-k
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k <= B) {
                int rem = l % k;
                int start = (l - rem) / k;
                int end = (r - rem) / k;
                small[k][rem].push_back({start, end, v});
            } else {
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (long long)nums[idx] * v % MOD;
                }
            }
        }

        // Process all small-k groups
        for (int k = 1; k <= B; k++) {
            for (int rem = 0; rem < k; rem++) {
                int len = 0;
                for (int idx = rem; idx < n; idx += k) len++;

                if (len == 0 || small[k][rem].empty()) continue;

                vector<long long> diff(len + 1, 1);

                for (auto &seg : small[k][rem]) {
                    int start = seg[0];
                    int end = seg[1];
                    int v = seg[2];

                    diff[start] = diff[start] * v % MOD;
                    if (end + 1 < len) {
                        diff[end + 1] = diff[end + 1] * modPow(v, MOD - 2) % MOD;
                    }
                }

                long long cur = 1;
                int t = 0;
                for (int idx = rem; idx < n; idx += k, t++) {
                    cur = cur * diff[t] % MOD;
                    nums[idx] = (long long)nums[idx] * cur % MOD;
                }
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};