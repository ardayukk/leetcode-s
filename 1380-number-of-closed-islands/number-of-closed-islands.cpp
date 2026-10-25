class Solution {
private:
    int rows, cols;

    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }
        
        if (grid[r][c] == 1) {
            return true;
        }

        grid[r][c] = 1;

        bool up = dfs(grid, r - 1, c);
        bool down = dfs(grid, r + 1, c);
        bool left = dfs(grid, r, c - 1);
        bool right = dfs(grid, r, c + 1);

        return up && down && left && right;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        rows = grid.size();
        cols = grid[0].size();
        int closedIslandsCount = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    if (dfs(grid, r, c)) {
                        closedIslandsCount++;
                    }
                }
            }
        }

        return closedIslandsCount;
    }
};
