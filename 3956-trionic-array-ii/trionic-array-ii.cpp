class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        const long long NEG = -(1LL << 60); // safe -infinity
        int n = (int)nums.size();
        if (n < 4) return 0;

        long long inc1 = NEG; // increasing (len >= 2)
        long long dec  = NEG; // inc then dec (both non-empty)
        long long inc2 = NEG; // inc then dec then inc (all non-empty)
        long long ans  = NEG;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                inc1 = dec = inc2 = NEG;
                continue;
            }

            if (nums[i] > nums[i - 1]) { // ↑
                long long newInc2 = NEG;
                if (inc2 != NEG) newInc2 = max(newInc2, inc2 + nums[i]); // extend final ↑
                if (dec  != NEG) newInc2 = max(newInc2, dec  + nums[i]); // start final ↑ after ↓

                long long newInc1 = max(
                    (inc1 != NEG ? inc1 + nums[i] : NEG),                // extend first ↑
                    (long long)nums[i - 1] + nums[i]                     // start new first ↑ (len=2)
                );

                inc1 = newInc1;
                dec  = NEG;
                inc2 = newInc2;

                if (inc2 != NEG) ans = max(ans, inc2);
            }
            else { // ↓
                long long newDec = NEG;
                if (dec  != NEG) newDec = max(newDec, dec  + nums[i]);   // extend ↓
                if (inc1 != NEG) newDec = max(newDec, inc1 + nums[i]);   // start ↓ after first ↑

                inc1 = NEG;
                dec  = newDec;
                inc2 = NEG;
            }
        }

        return (ans == NEG ? 0 : ans);
    }
};
