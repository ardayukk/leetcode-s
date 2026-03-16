class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> sums;   // distinct sums

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                // size 0 rhombus = single cell
                sums.insert(grid[r][c]);

                // len = distance from top corner to right/left corner
                for (int len = 1; r + 2 * len < m && c - len >= 0 && c + len < n; len++) {
                    int cur = 0;

                    // top -> right
                    for (int t = 0; t < len; t++) {
                        cur += grid[r + t][c + t];
                    }

                    // right -> bottom
                    for (int t = 0; t < len; t++) {
                        cur += grid[r + len + t][c + len - t];
                    }

                    // bottom -> left
                    for (int t = 0; t < len; t++) {
                        cur += grid[r + 2 * len - t][c - t];
                    }

                    // left -> top
                    for (int t = 0; t < len; t++) {
                        cur += grid[r + len - t][c - len + t];
                    }

                    sums.insert(cur);
                }
            }
        }

        vector<int> ans;
        for (auto it = sums.rbegin(); it != sums.rend() && ans.size() < 3; ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};