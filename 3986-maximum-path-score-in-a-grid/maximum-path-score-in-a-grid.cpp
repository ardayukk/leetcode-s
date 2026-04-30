class Solution {
public:
    int calcPenalty(int k){
        if(k == 0) return 0;
        return 1;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                m,
                vector<int>(k + 1, -1)
            )
        );

        int cost = calcPenalty(grid[0][0]);
        dp[0][0][k - cost] = grid[0][0];

        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                for(int newk = 0; newk <= k; newk++){
                    if(dp[x][y][newk] == -1) continue;

                    if(x + 1 < n){
                        int cost = calcPenalty(grid[x + 1][y]);

                        if(newk >= cost){
                            int rem = newk - cost;

                            dp[x + 1][y][rem] =
                                max(dp[x + 1][y][rem],
                                    dp[x][y][newk] + grid[x + 1][y]);
                        }
                    }

                    if(y + 1 < m){
                        int cost = calcPenalty(grid[x][y + 1]);

                        if(newk >= cost){
                            int rem = newk - cost;

                            dp[x][y + 1][rem] =
                                max(dp[x][y + 1][rem],
                                    dp[x][y][newk] + grid[x][y + 1]);
                        }
                    }
                }
            }
        }

        int soln = -1;

        for(int i = 0; i <= k; i++){
            soln = max(soln, dp[n - 1][m - 1][i]);
        }

        return soln;
    }
};