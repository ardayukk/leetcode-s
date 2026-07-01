#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> dist;

    bool canReach(int safeness) {
        if (dist[0][0] < safeness || dist[n - 1][m - 1] < safeness) {
            return false;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        q.push({0, 0});
        visited[0][0] = true;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == m - 1) {
                return true;
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visited[nx][ny]) continue;

                if (dist[nx][ny] < safeness) continue;

                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dist.assign(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Multi-source BFS: fills nearest-thief distance for all cells.
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }

        // Answer is between 0 and n + m - 2.
        int low = 0;
        int high = n + m - 2;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canReach(mid)) {
                ans = mid;
                low = mid + 1;   // see whether a safer path exists
            } else {
                high = mid - 1;  // requirement is too strict
            }
        }

        return ans;
    }
};