#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<int> tz(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) cnt++;
                else break;
            }
            tz[i] = cnt;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int need = n - 1 - i;
            int j = i;
            while (j < n && tz[j] < need) j++;
            if (j == n) return -1;

            ans += (j - i);
            int val = tz[j];
            for (int k = j; k > i; k--) tz[k] = tz[k - 1];
            tz[i] = val;
        }

        return (int)ans;
    }
};