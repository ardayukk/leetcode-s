class Solution {
public:
    int concatenatedBinary(int n) {
        
        const long long MOD = 1000000007LL;
        long long ans = 0;
        int len = 0; // current bit-length

        for(int i = 1; i <= n; i++){
            if((i & (i - 1)) == 0) len++;
            ans = ((ans << len) + i) % MOD;
        }
        return ans;
    }
};