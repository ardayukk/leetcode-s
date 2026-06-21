class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> cnt(maxCost + 1, 0);

        for (int c : costs) {
            cnt[c]++;
        }

        int ans = 0;

        for (int cost = 1; cost <= maxCost; cost++) {
            if (cnt[cost] == 0) continue;

            int canBuy = min(cnt[cost], coins / cost);
            ans += canBuy;
            coins -= canBuy * cost;
        }

        return ans;
    }
};