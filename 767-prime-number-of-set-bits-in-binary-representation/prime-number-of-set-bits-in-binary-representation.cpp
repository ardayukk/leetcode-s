class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int c = 0;
        for (int x = left; x <= right; x++) {
            c += isp(x);
        }
        return c;
    }

    bool isp(int x) {
        int a = __builtin_popcount(x);
        if (a < 2) return false;
        for (int d = 2; d * d <= a; d++) {
            if (a % d == 0) return false;
        }
        return true;
    }

    int count1s(int x) {
        int c = 0;
        while (x != 0) {
            c += (x & 1);
            x >>= 1;
        }
        return c;
    }
};