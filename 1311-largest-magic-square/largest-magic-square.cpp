#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int K = min(m, n);

        vector<vector<long long>> rowPref(m, vector<long long>(n + 1, 0));
        vector<vector<long long>> colPref(m + 1, vector<long long>(n, 0));

        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                rowPref[i][j + 1] = rowPref[i][j] + grid[i][j];
                colPref[i + 1][j] = colPref[i][j] + grid[i][j];
            }
        }

        vector<vector<long long>> diagPref(m + 1, vector<long long>(n + 1, 0));//-\>
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                diagPref[i + 1][j + 1] = diagPref[i][j] + grid[i][j];
            }
        }
        
        vector<vector<long long>> antiPref(m + 1, vector<long long>(n + 1, 0));

        for(int i = 0; i < m; i++){
            for(int j = n - 1; j >= 0; j--){
                antiPref[i + 1][j] = antiPref[i][j + 1] + grid[i][j];
            }
        }

        auto rowSum = [&](int r, int c1, int c2) -> long long {
            return rowPref[r][c2 + 1] - rowPref[r][c1];
        };

        auto colSum = [&](int c , int r1, int r2) -> long long {
            return colPref[r2 + 1][c] - colPref[r1][c];
        };

        auto diagSum = [&](int r, int c, int k) -> long long {
            return diagPref[r + k][c + k] - diagPref[r][c];
        };
        auto antiDiagSum = [&](int r, int c, int k) -> long long {
            return antiPref[r + k][c] - antiPref[r][c + k];
        };

        for(int k = K; k > 1; k--){
            for(int r = 0; r <= m - k; r++){
                for(int c = 0; c <= n - k; c++){
                    long long target = diagSum(r, c, k);
                    if (antiDiagSum(r, c, k) != target) continue;

                    bool ok = true;

                    // check all rows
                    for (int i = 0; i < k && ok; i++) {
                        if (rowSum(r + i, c, c + k - 1) != target) ok = false;
                    }
                    for (int j = 0; j < k && ok; j++) {
                        if (colSum(c + j, r, r + k - 1) != target) ok = false;
                    }

                    if (ok) return k;
                }
            }
        }
        return 1;
    }
};
