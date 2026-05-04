class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transformMatrix(matrix);
        reverseRows(matrix);
    }
    void reverseRows(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n / 2; j++){
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
        return;
    }
    void transformMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = rows > 0 ? matrix[0].size() : 0;
    vector<vector<int>> result(cols, vector<int>(rows, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }

        matrix = result;
        return;
    }
};