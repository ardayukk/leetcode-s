class Solution {
public:
    using ll = long long;

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll l = 0;
        ll r = 1LL * (*min_element(workerTimes.begin(), workerTimes.end())) 
               * mountainHeight * (mountainHeight + 1) / 2;
        ll ans = r;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (calculate(mountainHeight, workerTimes, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    bool calculate(int mountainHeight, vector<int>& workerTimes, ll time) {
        ll total = 0;

        for (int a : workerTimes) {
            ll x = time / a;
            ll k = (ll)((sqrt(1.0 + 8.0 * x) - 1) / 2); // floor
            total += k;
            if (total >= mountainHeight) return true;
        }

        return total >= mountainHeight;
    }
};