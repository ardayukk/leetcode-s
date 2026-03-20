class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> vals;
                vals.reserve(k * k);

                // collect this k x k submatrix
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        vals.push_back(grid[r][c]);
                    }
                }

                sort(vals.begin(), vals.end());

                int best = INT_MAX;
                for (int t = 1; t < (int)vals.size(); t++) {
                    if (vals[t] != vals[t - 1]) {
                        best = min(best, vals[t] - vals[t - 1]);
                    }
                }

                ans[i][j] = (best == INT_MAX ? 0 : best);
            }
        }

        return ans;
    }
};