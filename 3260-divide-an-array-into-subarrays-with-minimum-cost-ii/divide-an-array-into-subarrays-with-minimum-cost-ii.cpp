#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = (int)nums.size();

        // If k == 1, we keep the whole array as 1 subarray.
        // Cost is just the first element.
        if (k == 1) return nums[0];

        // The "start indices" we are allowed to choose are 1..n-1.
        // The maximum possible span between chosen indices is (n-1) - 1 = n-2.
        // If dist is bigger than that, the constraint becomes irrelevant, so clamping is safe.
        if (n >= 2) dist = min(dist, n - 2);

        // We need to pick (k-1) starting points for subarrays 2..k inside some window of length (dist+1).
        const int need = k - 1;

        // If need > dist+1, it's impossible to choose that many distinct indices in a window of length dist+1.
        // LeetCode test data typically guarantees feasibility, but we keep a guard anyway.
        if (need > dist + 1) return -1;

        // --- Data structure: two multisets ---
        // small = the "need" smallest elements in the current window
        // big   = everything else
        // sumSmall = sum(small)
        multiset<int> small, big;
        long long sumSmall = 0;

        auto balance = [&]() {
            // Ensure small has exactly 'need' elements (as long as possible).
            // 1) If small is too big, move its largest elements to big.
            while ((int)small.size() > need) {
                auto it = prev(small.end()); // iterator to largest element
                int x = *it;
                sumSmall -= x;
                big.insert(x);
                small.erase(it);
            }
            // 2) If small is too small, move the smallest elements from big into small.
            while ((int)small.size() < need && !big.empty()) {
                auto it = big.begin(); // iterator to smallest element
                int x = *it;
                sumSmall += x;
                small.insert(x);
                big.erase(it);
            }
        };

        auto add = [&](int x) {
            // Insert x into the correct multiset.
            // Rule: x belongs to 'small' if it's <= largest element of small,
            // otherwise it belongs to 'big'.
            //
            // This keeps the invariant: every element in small <= every element in big.
            if (need == 0) {
                // (Not really needed here since k>=2 => need>=1, but kept for completeness.)
                big.insert(x);
                return;
            }

            if (small.empty() || x <= *prev(small.end())) {
                small.insert(x);
                sumSmall += x;
            } else {
                big.insert(x);
            }

            balance();
        };

        auto removeOne = [&](int x) {
            // Remove one occurrence of x from whichever multiset contains it.
            auto itSmall = small.find(x);
            if (itSmall != small.end()) {
                sumSmall -= x;
                small.erase(itSmall);
            } else {
                auto itBig = big.find(x);
                // In correct sliding-window logic, itBig must exist.
                big.erase(itBig);
            }

            balance();
        };

        // ------------------------------------------------------------
        // Sliding window over indices [1..n-1] with window length (dist+1).
        //
        // Window 1: indices [1, 1+dist]
        // Window 2: indices [2, 2+dist]
        // ...
        // Last:     indices [n-1-dist, n-1]
        //
        // For each window, sumSmall = sum of the smallest (k-1) values in that window.
        // Answer is nums[0] + min(sumSmall).
        // ------------------------------------------------------------

        // Build the first window: indices [1 .. dist+1]
        // (Because window length is dist+1.)
        for (int idx = 1; idx <= dist + 1; ++idx) {
            add(nums[idx]);
        }

        long long bestWindow = sumSmall; // best sum of (k-1) smallest in any window so far

        // Slide the window: right endpoint goes from (dist+2) up to (n-1)
        for (int right = dist + 2; right <= n - 1; ++right) {
            int left = right - (dist + 1); // index that leaves the window

            // Remove outgoing element
            removeOne(nums[left]);

            // Add incoming element
            add(nums[right]);

            // Update best
            bestWindow = min(bestWindow, sumSmall);
        }

        // nums[0] is always part of the cost (first subarray starts at 0).
        return (long long)nums[0] + bestWindow;
    }
};
