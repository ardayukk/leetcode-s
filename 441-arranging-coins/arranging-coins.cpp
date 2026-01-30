class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((sqrt(1LL + 8LL * n) - 1) / 2);
    }
};
