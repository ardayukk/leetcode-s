typedef unsigned __int128 uint128_t;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            v[i] = (int)choose(rowIndex, i);
        }
        return v;
    }

private:
    // factorial cache: fact[i] = i!
    static vector<uint128_t> fact;

    static void ensureFact(int n) {
        if ((int)fact.size() > n) return;      // already have up to n
        int start = (int)fact.size();          // first missing index
        fact.resize(n + 1);
        for (int i = start; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }

    static uint128_t factorial(int n) {
        ensureFact(n);
        return fact[n];
    }

    static uint128_t choose(int n, int k) {
        ensureFact(n);
        return factorial(n) / (factorial(k) * factorial(n - k));
    }
};

// static member definition
vector<uint128_t> Solution::fact = {1}; // 0! = 1