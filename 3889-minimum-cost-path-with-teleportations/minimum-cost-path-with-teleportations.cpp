#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // If LeetCode expects a different name (e.g. minimumCostPath), just rename this.
    int minCost(vector<vector<int>>& grid, int k) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        const int INF = 1e9;

        // ---- 1) Compress values (grid[i][j] up to 1e4, but we compress to <= m*n unique) ----
        vector<int> vals;
        vals.reserve(m * n);
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                vals.push_back(grid[r][c]);

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int U = (int)vals.size(); // number of unique values

        // Map each cell value -> compressed index [0..U-1]
        // Since values <= 1e4, we can use an array mapping directly.
        vector<int> valToIdx(10001, -1);
        for (int i = 0; i < U; i++) valToIdx[vals[i]] = i;

        vector<vector<int>> idx(m, vector<int>(n));
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                idx[r][c] = valToIdx[grid[r][c]];

        /*
        distPrev[r][c] = minimum cost to reach (r,c) using AT MOST (t-1) teleports
        distCurr[r][c] = minimum cost to reach (r,c) using AT MOST t teleports
        We iterate t = 0..k.
        */
        vector<vector<int>> distPrev(m, vector<int>(n, INF));
        vector<vector<int>> distCurr(m, vector<int>(n, INF));

        // ---- 2) Base layer t = 0 (no teleports allowed) ----
        // Starting at (0,0) costs 0 because you don't "enter" the start cell.
        distPrev[0][0] = 0;

        // Standard right/down DP:
        // dist[r][c] = min(dist[r-1][c], dist[r][c-1]) + grid[r][c] (except start)
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r == 0 && c == 0) continue;
                int best = INF;
                if (r > 0) best = min(best, distPrev[r-1][c]);
                if (c > 0) best = min(best, distPrev[r][c-1]);
                if (best < INF) distPrev[r][c] = best + grid[r][c];
            }
        }

        // ---- 3) Layers t = 1..k ----
        for (int t = 1; t <= k; t++) {

            /*
            We want to compute for every value index i:
              bestAtValue[i] = min distPrev[r][c] among cells with compressed value i

            Then compute suffix minimum:
              suffixMin[i] = min bestAtValue[j] for all j >= i
            This represents:
              "minimum cost among all reachable source cells whose value >= vals[i]"
            which is exactly what we need for teleporting into any cell of value vals[i].
            */

            vector<int> bestAtValue(U, INF);

            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    int vIdx = idx[r][c];
                    bestAtValue[vIdx] = min(bestAtValue[vIdx], distPrev[r][c]);
                }
            }

            vector<int> suffixMin(U, INF);
            for (int i = U - 1; i >= 0; i--) {
                suffixMin[i] = bestAtValue[i];
                if (i + 1 < U) suffixMin[i] = min(suffixMin[i], suffixMin[i + 1]);
            }

            /*
            Now build the "initial cost" for distCurr:
              initCost[r][c] = min(
                  distPrev[r][c],                     // don't use the t-th teleport at all
                  suffixMin[idx[r][c]]                // use 1 teleport to arrive here for free
              )

            Then compute distCurr with normal right/down transitions (DAG DP).
            */
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    distCurr[r][c] = INF; // reset
                }
            }

            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {

                    // Option A: arrive here without using a new teleport (carry from previous layer)
                    int best = distPrev[r][c];

                    // Option B: arrive here by teleporting from some source with value >= this cell value
                    int tele = suffixMin[idx[r][c]];
                    best = min(best, tele);

                    // Now allow normal moves inside this layer (right/down):
                    // Coming from up/left means we "enter" (r,c), so add grid[r][c].
                    // But careful at start cell: entering cost isn't applied if we're "starting" here.
                    if (r == 0 && c == 0) {
                        // Start cell: cost is just best (no +grid[0][0])
                        distCurr[r][c] = min(distCurr[r][c], best);
                    } else {
                        int fromUp = (r > 0 && distCurr[r-1][c] < INF) ? distCurr[r-1][c] + grid[r][c] : INF;
                        int fromLeft = (c > 0 && distCurr[r][c-1] < INF) ? distCurr[r][c-1] + grid[r][c] : INF;

                        distCurr[r][c] = min({best, fromUp, fromLeft});
                    }
                }
            }

            // Move to next layer
            distPrev.swap(distCurr);
        }

        return distPrev[m-1][n-1];
    }
};
