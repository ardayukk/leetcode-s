class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();

        int best = 1;          // at least 1 element can be kept
        int l = 0;

        for (int r = 0; r < n; r++) {
            // shrink l until condition holds: nums[r] <= k * nums[l]
            while (l <= r && (long long)nums[r] > (long long)k * (long long)nums[l]) {
                l++;
            }
            // now [l..r] is valid (balanced if we keep exactly these)
            best = max(best, r - l + 1);
        }

        return n - best;
    }
};
