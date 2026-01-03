class Solution {
public:
    using ll = long long;
    const ll MAX = 1000000007LL;
    int numOfWays(int n) {
        ll dp2 = 6;
        ll dp3 = 6;

        for(int i = 1; i < n; i++){
            int prevdp2 = dp2;
            dp2 = 3 * dp2 + 2 * dp3;
            dp3 = 2 * prevdp2 + 2 * dp3;
            dp3 = dp3 % MAX;
            dp2 = dp2 % MAX;
        }
        cout << dp2 << endl;
        return (int)((dp2 + dp3) % MAX);
    }
};