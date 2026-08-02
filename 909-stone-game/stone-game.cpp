class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        vector<vector<pair<int, int>>> dp(
            n,
            vector<pair<int, int>>(n, {0, 0})
        );

        // Intervals containing one number
        for (int i = 0; i < n; i++) {
            dp[i][i] = {piles[i], 0};
        }

        // len = length of the interval
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                // Current player chooses piles[l]
                int takeLeftCurrent =
                    piles[l] + dp[l + 1][r].second;

                int takeLeftOther =
                    dp[l + 1][r].first;

                // Current player chooses piles[r]
                int takeRightCurrent =
                    piles[r] + dp[l][r - 1].second;

                int takeRightOther =
                    dp[l][r - 1].first;

                if (takeLeftCurrent >= takeRightCurrent) {
                    dp[l][r] = {
                        takeLeftCurrent,
                        takeLeftOther
                    };
                } else {
                    dp[l][r] = {
                        takeRightCurrent,
                        takeRightOther
                    };
                }
            }
        }

        return dp[0][n - 1].first >= dp[0][n - 1].second;
    }
};