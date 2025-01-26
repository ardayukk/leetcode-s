#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int rows = 2;
        int cols = colsum.size();

        vector<vector<int>> arr(rows, vector<int>(cols, -1));

        for (int i = 0; i < cols; i++) {
            if (colsum.at(i) == 0) {
                arr[0][i] = 0;
                arr[1][i] = 0;
            } else if (colsum.at(i) == 2) {
                arr[0][i] = 1;
                arr[1][i] = 1;
                upper--;
                lower--;
            } else if (colsum.at(i) == 1) {
                if (upper > lower) {
                    arr[0][i] = 1;
                    arr[1][i] = 0;
                    upper--;
                } else {
                    arr[0][i] = 0;
                    arr[1][i] = 1;
                    lower--;
                }
            }
        }

        if (upper != 0 || lower != 0) {
            return {};
        }

        return arr;
    }
};
