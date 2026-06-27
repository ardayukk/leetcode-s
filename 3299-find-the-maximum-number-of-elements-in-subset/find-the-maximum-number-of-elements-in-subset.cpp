class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        long long maxVal = 0;

        for (int x : nums) {
            freq[x]++;
            maxVal = max(maxVal, 1LL * x);
        }

        auto cnt = [&](long long x) -> int {
            auto it = freq.find(x);
            if (it == freq.end()) return 0;
            return it->second;
        };

        int ans = 1;

        int ones = cnt(1);
        if (ones > 0) {
            if (ones % 2 == 0) ones--;
            ans = max(ans, ones);
        }

        for (auto [num, f] : freq) {
            if (num == 1) continue;

            long long curr = num;
            int count = 0;

            while (cnt(curr) >= 2) {
                count += 2;

                if (curr > maxVal / curr) break;

                curr = curr * curr;
            }

            if (cnt(curr) == 1) {
                count++;
            } else {
                count--;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};