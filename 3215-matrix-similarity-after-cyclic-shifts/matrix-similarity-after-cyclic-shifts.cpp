class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> matcpy = mat;

        int n = mat.size();
        if(n == 0) return true;

        int m = mat[0].size();
        k %= m;

        for(int s = 0; s < k; s++){
            for(int i = 0; i < n; i += 2){
                int a = mat[i][0];

                for(int j = 1; j < m; j++){
                    mat[i][j - 1] = mat[i][j];
                }
                mat[i][m - 1] = a;
            }

            for(int i = 1; i < n; i += 2){
                int a = mat[i][m - 1];

                for(int j = m - 2; j >= 0; j--){
                    mat[i][j + 1] = mat[i][j];
                }
                mat[i][0] = a;
            }
        }

        return mat == matcpy;
    }
};