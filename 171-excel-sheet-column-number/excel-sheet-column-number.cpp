class Solution {
public:
    static int p26[7];

    int titleToNumber(string columnTitle) {
        int sum = 0;
        int n = columnTitle.size();

        for(int i = 0; i < n; i++){
            sum += (columnTitle[i] - 'A' + 1) * p26[n - i - 1];
        }
        return sum;
    }
};

// Precompute once globally
int Solution::p26[7] = {
    1,
    26,
    676,
    17576,
    456976,
    11881376,
    308915776
};
