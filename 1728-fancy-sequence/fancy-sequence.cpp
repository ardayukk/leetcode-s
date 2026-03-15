class Fancy {
public:
    using ll = long long;
    static const int MOD = 1e9 + 7;

    vector<ll> arr;   // stores normalized values
    ll mul, add;      // global transform: real = stored * mul + add

    Fancy() {
        mul = 1;
        add = 0;
    }

    ll modPow(ll a, ll e) {
        ll res = 1;
        a %= MOD;
        while (e > 0) {
            if (e & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return res;
    }

    ll modInv(ll x) {
        return modPow(x, MOD - 2);
    }
    
    void append(int val) {
        // store normalized value x so that:
        // x * mul + add == val (mod MOD)
        ll x = ((val - add) % MOD + MOD) % MOD;
        x = (x * modInv(mul)) % MOD;
        arr.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= (int)arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};