class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> lenAfter(n);
        long long len = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c == '*') {
                if (len > 0) len--;
            } 
            else if (c == '#') {
                len *= 2;
            } 
            else if (c == '%') {
                // length unchanged
            } 
            else {
                len++;
            }

            lenAfter[i] = len;
        }

        if (k >= len) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long sz = lenAfter[i];

            if (c == '*') {
                continue;
            }
            else if (c == '#') {
                long long half = sz / 2;
                if (k >= half) k -= half;
            }
            else if (c == '%') {
                k = sz - 1 - k;
            }
            else {
                if (k == sz - 1) return c;
            }
        }

        return '.';
    }
};