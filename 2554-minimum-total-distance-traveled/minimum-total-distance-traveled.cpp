class Solution {
public:
    using ll = long long;
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> newfac;

        for (auto& f : factory) {
            for (int i = 0; i < f[1]; i++) {
                newfac.push_back(f[0]);
            }
        }

        int n = robot.size();
        int m = newfac.size();
        vector<vector<ll>> dp(m, vector<ll>(n, LLONG_MAX / 2));


        dp[0][0] = abs(newfac[0] - robot[0]);
        for (int i = 1; i < m; i++) {
            dp[i][0] = min(dp[i-1][0], (ll) abs(newfac[i] - robot[0]));
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = LLONG_MAX / 2;
        }


        for (int j = 1; j < n; j++) {
            for (int i = j; i < m; i++) {
                if(dp[i-1][j-1] != LLONG_MAX/2){
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(newfac[i] - robot[j]));
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};