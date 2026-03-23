class Solution {
public:
    using ll = long long;
    ll MOD = 1000000007LL;

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<ll>> dpMAX(n, vector<ll>(m));
        vector<vector<ll>> dpMIN(n, vector<ll>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ll temp0, temp1;
                if(i == 0 && j == 0){
                    dpMIN[i][j] = grid[i][j];


                    dpMAX[i][j] = grid[i][j];
                }
                else if(i == 0){
                    temp0 = grid[i][j] * dpMIN[i][j - 1];
                    temp1 = grid[i][j] * dpMAX[i][j - 1];
                    dpMIN[i][j] = min(temp0, temp1);
                    dpMIN[i][j] %= MOD;

                    
                    dpMAX[i][j] = max(temp0, temp1);
                    dpMAX[i][j] %= MOD;
                }
                else if(j == 0){
                    temp0 = grid[i][j] * dpMIN[i - 1][j];
                    temp1 = grid[i][j] * dpMAX[i - 1][j]; 
                    dpMIN[i][j] = min(temp0,temp1);


                    dpMAX[i][j] = max(temp0,temp1);

                }
                else{
                    temp0 = min(grid[i][j] * dpMIN[i - 1][j], grid[i][j] * dpMIN[i][j - 1]);
                    temp1 = min(grid[i][j] * dpMAX[i - 1][j], grid[i][j] * dpMAX[i][j - 1]);
                    dpMIN[i][j] = min(temp0, temp1);

                    temp0 = max(grid[i][j] * dpMIN[i - 1][j], grid[i][j] * dpMIN[i][j - 1]);
                    temp1 = max(grid[i][j] * dpMAX[i - 1][j], grid[i][j] * dpMAX[i][j - 1]);
                    dpMAX[i][j] = max(temp0, temp1);
                }
            }
        }

        ll ans = dpMAX[n - 1][m - 1];
        return (ans >= 0) ? ans % MOD : -1;
    }
};