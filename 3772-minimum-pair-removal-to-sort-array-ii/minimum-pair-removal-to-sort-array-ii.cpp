#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) return 0;

        vector<long long> val(n);
        for (int i = 0; i < n; i++) val[i] = nums[i];

        vector<int> L(n), R(n);
        vector<char> alive(n, 1);

        for (int i = 0; i < n; i++) {
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[n - 1] = -1;

        long long bad = 0;
        for (int i = 0; i < n; i++) {
            int j = R[i];
            if (j != -1 && val[i] > val[j]) bad++;
        }

        struct Item {
            long long sum;
            int i, j;
        };
        struct Cmp {
            bool operator()(const Item& a, const Item& b) const {
                if (a.sum != b.sum) return a.sum > b.sum; // min by sum
                return a.i > b.i; // tie -> leftmost pair
            }
        };

        priority_queue<Item, vector<Item>, Cmp> pq;

        auto pushPair = [&](int i) {
            if (i == -1 || !alive[i]) return;
            int j = R[i];
            if (j == -1 || !alive[j]) return;
            pq.push({val[i] + val[j], i, j});
        };

        for (int i = 0; i < n - 1; i++) pushPair(i);

        auto isBad = [&](int x, int y) -> bool {
            return (x != -1 && y != -1 && alive[x] && alive[y] && val[x] > val[y]);
        };

        int ops = 0;

        while (bad > 0) {
            Item cur;

            // Pop until we find a fully valid (non-stale) adjacent pair
            while (true) {
                cur = pq.top();
                pq.pop();

                int i = cur.i, j = cur.j;
                if (!alive[i] || !alive[j]) continue;
                if (R[i] != j) continue; // not adjacent anymore
                long long realSum = val[i] + val[j];
                if (cur.sum != realSum) continue; // <-- CRUCIAL: sum stale
                break;
            }

            int i = cur.i;
            int j = cur.j;

            int a = L[i];
            int d = R[j];

            // remove contributions of old edges
            if (isBad(a, i)) bad--;
            if (isBad(i, j)) bad--;
            if (isBad(j, d)) bad--;

            // merge j into i
            val[i] += val[j];
            alive[j] = 0;

            // relink
            R[i] = d;
            if (d != -1) L[d] = i;

            // add contributions of new edges (a,i) and (i,d)
            if (isBad(a, i)) bad++;
            if (isBad(i, d)) bad++;

            // push affected pairs with fresh sums
            if (a != -1) pushPair(a);
            pushPair(i);

            ops++;
        }

        return ops;
    }
};
