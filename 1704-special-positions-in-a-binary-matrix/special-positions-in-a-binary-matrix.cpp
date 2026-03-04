class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = (int)mat.size();
        int n = (int)mat[0].size();

        // rowPref[i][k] = sum of mat[i][0..k-1]
        vector<vector<int>> rowPref(m, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowPref[i][j + 1] = rowPref[i][j] + mat[i][j];
            }
        }

        // colPref[j][k] = sum of mat[0..k-1][j]
        vector<vector<int>> colPref(n, vector<int>(m + 1, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colPref[j][i + 1] = colPref[j][i] + mat[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            int rowSum = rowPref[i][n];
            if (rowSum != 1) continue; // small prune
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && colPref[j][m] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};