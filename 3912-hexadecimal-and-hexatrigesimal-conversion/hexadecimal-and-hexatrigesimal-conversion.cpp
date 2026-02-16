class Solution {
public:
    string toBase(long long x, int base) {
        if (x == 0) return "0";
        
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res = "";
        
        while (x > 0) {
            res += digits[x % base];
            x /= base;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }

    string concatHex36(int n) {
        long long sq = 1LL * n * n;
        long long cube = 1LL * n * n * n;
        
        return toBase(sq, 16) + toBase(cube, 36);
    }
};
