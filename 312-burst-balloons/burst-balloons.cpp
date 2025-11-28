class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // padded array
        vector<int> val(n + 2);
        val[0] = 1;
        val[n+1] = 1;
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i-1];
        }

        // dp table (n+2 x n+2)
        int** dp = new int*[n+2];
        for (int i = 0; i < n+2; i++) {
            dp[i] = new int[n+2];
        }

        // initialize dp[i][j] = 0
        for (int i = 0; i < n+2; i++)
            for (int j = 0; j < n+2; j++)
                dp[i][j] = 0;

        // fill by interval length
        for (int len = 2; len < n+2; len++) {
            for (int i = 0; i + len < n+2; i++) {
                int j = i + len;

                // compute dp[i][j]
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i][k] + dp[k][j] + val[i] * val[k] * val[j]
                    );
                }
            }
        }

        return dp[0][n+1];
    }
};
