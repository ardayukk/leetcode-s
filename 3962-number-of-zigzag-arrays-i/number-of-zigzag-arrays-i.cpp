class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(2, vector<long long>(m, 0))
        );

        for (int x = 0; x < m; x++) {
            dp[1][0][x] = 1;
            dp[1][1][x] = 1;
        }
        
        vector<long long> pref(m), suff(m);
        for (int len = 1; len < n; len++) {


            pref[0] = dp[len][1][0];
            for (int x = 1; x < m; x++) {
                pref[x] = (pref[x - 1] + dp[len][1][x]) % MOD;
            }

            suff[m - 1] = dp[len][0][m - 1];
            for (int x = m - 2; x >= 0; x--) {
                suff[x] = (suff[x + 1] + dp[len][0][x]) % MOD;
            }

            for (int y = 0; y < m; y++) {

                dp[len + 1][0][y] =
                    (y > 0 ? pref[y - 1] : 0);

                dp[len + 1][1][y] =
                    (y + 1 < m ? suff[y + 1] : 0);
            }
        }

        long long ans = 0;

        for (int x = 0; x < m; x++) {
            ans = (ans + dp[n][0][x]) % MOD;
            ans = (ans + dp[n][1][x]) % MOD;
        }

        return (int)ans;
    }
};