#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row(query_row + 2, 0.0); // +2 so row[c+1] is safe
        row[0] = (double)poured;

        for (int r = 0; r < query_row; r++) {
            vector<double> next(query_row + 2, 0.0);
            for (int c = 0; c <= r; c++) {
                double overflow = max(0.0, row[c] - 1.0);
                if (overflow > 0.0) {
                    next[c]     += overflow / 2.0;
                    next[c + 1] += overflow / 2.0;
                }
            }
            row.swap(next);
        }

        return min(1.0, row[query_glass]);
    }
};
